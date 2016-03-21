 ///
 /// @file    consumerthread.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-19 03:12:03
 ///

#include "consumerthread.h"
#include "buffer.h"
#include <stdio.h>
#include <unistd.h>
#include <iostream>

using std::cout;
using std::endl;

namespace yy{
	void ConsumerThread::run(){
		while(true){
			cout<<"consumer num -->"<<_buffer.pop()<<endl;
			sleep(1);
		}
	}
}
