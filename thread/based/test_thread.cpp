 ///
 /// @file    test_thread.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-18 08:20:46
 ///

#include "thread.h"
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>

using std::endl;
using std::cout;

struct Task{
	void run(){
		srand(time(NULL));
		while(true){
			int num = rand() % 100;
			cout<<"num -->"<<num<<endl;
			sleep(1);
		}
	}
};


int main(void){
	Task task;
	yy::Thread thread(std::bind(&Task::run,&task));
	thread.start();
	thread.join();
	return 0;
}
