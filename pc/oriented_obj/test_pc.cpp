 ///
 /// @file    test_pc.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-19 03:20:52
 ///

#include "buffer.h"
#include "productthread.h"
#include "consumerthread.h"

int main(void){
	yy::Buffer buffer(10);
	yy::Thread *product = new yy::ProductThread(buffer);
	yy::Thread *consumer = new yy::ConsumerThread(buffer);
	product->start();
	consumer->start();
	product->join();
	consumer->join();
	return 0;
}
