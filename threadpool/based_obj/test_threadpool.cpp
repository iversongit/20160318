 ///
 /// @file    test_threadpool.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-20 05:44:05
 ///

#include "threadpool.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <iostream>

using std::cout;
using std::endl;

struct Task{
	void process(){
		srand(time(NULL));
		int num = rand() % 100;
		cout<<"produce a num -->"<<num<<endl;
	}
};

int main(void){
	yy::ThreadPool threadpool(8,10);
	threadpool.start();
	int cnt = 10;
	Task task;
	while(cnt--){
		threadpool.addTask(std::bind(&Task::process,&task));
		sleep(1);
	}

	threadpool.stop();

	return 0;
}
