 ///
 /// @file    figure.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-18 05:48:42
 ///
 
#include <iostream>
#include <functional>

using std::cout;
using std::endl;

const float PI = 3.14159;

class Figure{
	public:
		typedef std::function<void()> DispCallback;
		typedef std::function<float()> AreaCallback;
		Figure(){}

		Figure(DispCallback disp,AreaCallback area)
		:_disp(disp)
		,_area(area)
		{
			cout<<"Figure(DispCallback,AreaCallback)"<<endl;
		}

		void setDispCallback(DispCallback disp){
			_disp = disp;
		}

		void setAreaCallback(AreaCallback area){
			_area = area;
		}

		void runDispCallback(){
			if(_disp) _disp();
		}

		float runAreaCallback(){
			if(_area) 
				return _area();
		}

	private:
		DispCallback _disp;
		AreaCallback _area;

};

class Circle{
	public:	
		Circle(float r)
		:_r(r)
		{
			cout<<"Circle(float)"<<endl;
		}

		void display(){
			cout<<"Circle: -->";
		}

		float area(){
			return PI * _r * _r;
		}

	private:
		float _r;
};

class Rectangle{
	public:
		Rectangle(float x,float y)
		:_x(x)
		,_y(y)
		{
			cout<<"Rectangle(float,float)"<<endl;
		}

		void display(){
			cout<<"Rectangle: -->";
		}

		float area(){
			return _x * _y;
		}

	private:
		float _x;
		float _y;
};

int main(void){
	Figure figure;
	Circle circle(6);

	figure.setDispCallback(std::bind(&Circle::display,&circle));
	figure.setAreaCallback(std::bind(&Circle::area,&circle));

	figure.runDispCallback();
	cout<< figure.runAreaCallback() <<endl;

	cout<<"-------------------------------"<<endl;

	Rectangle rect(8,10);
	figure.setDispCallback(std::bind(&Rectangle::display,&rect));
	figure.setAreaCallback(std::bind(&Rectangle::area,&rect));

	figure.runDispCallback();
	cout<<figure.runAreaCallback()<<endl;

	return 0;
}
