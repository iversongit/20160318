 ///
 /// @file    threadpool.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-20 05:07:03
 ///

#include "threadpool.h"
#include "threadpoolthread.h"
#include "task.h"
#include <unistd.h>
#include <iostream>

using std::cout;
using std::endl;

namespace yy{
	ThreadPool::ThreadPool(int threadnum,int bufsize)
	:_threadnum(threadnum)
	,_bufsize(bufsize)
	,_buffer(_bufsize)
	,_isExit(false)
	{
		_vecThreads.reserve(_threadnum);
	}

	ThreadPool::~ThreadPool(){
		if(!_isExit)
		{
			stop();
		}
	}

	void ThreadPool::start(){
		for(int i=0; i<_threadnum; i++){
			Thread *thread = new ThreadPoolThread(*this);
			_vecThreads.push_back(thread);
		}

		vector<Thread *>::iterator it;
		for(it = _vecThreads.begin(); it != _vecThreads.end(); ++it){
			(*it)->start();
		}
	}

	void ThreadPool::stop(){
		if(!_isExit){
			while(!_buffer.isempty()){
				sleep(1);
			}
			_isExit = true;
			vector<Thread *>::iterator it;
			for(it=_vecThreads.begin(); it != _vecThreads.end(); ++it){
				(*it)->join();
				delete (*it);
			}

			_vecThreads.clear();
		}
	}

	void ThreadPool::addTask(Task * task){
		_buffer.push(task);
	}

	Task * ThreadPool::getTask(){
		return _buffer.pop();
	}

	void ThreadPool::threadFunc(){
		while(!_isExit){
			Task * task = getTask();
			if(task) task->process();
		}
	}
}

