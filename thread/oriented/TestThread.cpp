 ///
 /// @file    TestThread.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-18 08:08:34
 ///

#include "TestThread.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <iostream>

using std::cout;
using std::endl;

namespace yy{
	void TestThread::run(){
		srand(time(NULL));
		while(true){
			int num = rand() % 100;
			cout<<"num -->"<<num<<endl;
			sleep(1);
		}
	}
}
