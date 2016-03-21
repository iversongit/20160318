 ///
 /// @file    productthread.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-19 02:46:14
 ///

#include "productthread.h"
#include "buffer.h"
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

namespace yy{
	ProductThread::ProductThread(Buffer & buffer)
	:_buffer(buffer)
	{}

	void ProductThread::run(){
		srand(time(NULL));
		int num;
		while(true){
			num = rand() % 100;
			cout<<"produce a num:"<<num<<endl;
			_buffer.push(num);
			sleep(1);
		}
	}
}
