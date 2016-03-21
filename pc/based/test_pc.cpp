 ///
 /// @file    test_pc.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-19 03:20:52
 ///

#include "buffer.h"
#include "thread.h"
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

struct Product{
	void produce(yy::Buffer & buffer)
	{
		srand(time(NULL));
		int num;
		while(true){
			num = rand() % 100;
			buffer.push(num);
			cout<<"produce a num -->"<<num<<endl;
			sleep(1);
		}
	}
};

struct Consumer{
	void consume(yy::Buffer & buffer)
	{
		while(true){
			cout<<"consume a num -->"<<buffer.pop()<<endl;
			sleep(2);
		}
	}
};
int main(void){
	yy::Buffer buffer(10);
	Product product;
	Consumer consumer;
	yy::Thread productthread(std::bind(&Product::produce,&product,std::ref(buffer)));
	yy::Thread consumerthread(std::bind(&Consumer::consume,&consumer,std::ref(buffer)));
	productthread.start();
	consumerthread.start();
	productthread.join();
	consumerthread.join();
	return 0;
}
