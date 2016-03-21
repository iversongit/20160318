 ///
 /// @file    function.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-18 05:04:14
 ///
 
#include <iostream>
#include <functional>
using std::endl;
using std::cout;

class Test{
	public:
		Test(int num): _num(num)
		{
			cout<<"Test(int)"<<endl;
		}

		void print_add(int i) const
		{
			cout<<"print_add(int) -->"<<_num + i<<endl;
		}
	private:
		int _num;
};

void print_num(int i){
	cout<<"print_num -->"<<i<<endl;
}

struct PrintNum{
	public:
		void operator()(int i) const
		{
			cout<<"operator()(int) -->"<<i<<endl;
		}
};

int main(void){
	std::function<void(int)> f1 = print_num;
	f1(66);

	f1 = PrintNum();
	f1(88);

	std::function<void(const Test &,int)> f2 = &Test::print_add;
	const Test test(100);
	f2(test,100);
	cout<<"-------------------------------"<<endl;

	std::function<void()> f3=std::bind(print_num,111);
	f3();

	f3 = std::bind(&Test::print_add,&test,110); 
	f3();
	return 0;
}
