 ///
 /// @file    test_threadpool.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-20 05:44:05
 ///
#include "task.h"
#include "threadpool.h"
#include <unistd.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void){
	yy::Task *task = new yy::MyTask;
	yy::ThreadPool threadpool(8,10);
	threadpool.start();
	int cnt = 10;
	while(cnt--){
		threadpool.addTask(task);
		sleep(1);
	}

	threadpool.stop();

	return 0;
}
