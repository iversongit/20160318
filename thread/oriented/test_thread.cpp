 ///
 /// @file    test_thread.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-18 08:20:46
 ///

#include "TestThread.h"
#include <iostream>

int main(void){
	yy::Thread * thread = new yy::TestThread;
	thread->start();
	thread->join();
	return 0;
}
