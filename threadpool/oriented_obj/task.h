 ///
 /// @file    task.h
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-21 00:43:22
 ///

#ifndef __TASK_H__
#define __TASK_H__


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <iostream>

using std::cout;
using std::endl;

namespace yy{
	class Task{
		public:
			virtual void process() = 0;
	};

	class MyTask : public Task{
		public:
			void process(){
				srand(time(NULL));
				int num = rand() % 100;
				cout<<"produce a num -->"<<num<<endl;
				sleep(1);
			}
	};
}
#endif
