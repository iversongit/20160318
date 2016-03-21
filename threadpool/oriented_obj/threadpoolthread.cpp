 ///
 /// @file    threadpoolthread.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-21 01:11:45
 ///
#include "threadpool.h"
#include "threadpoolthread.h"
#include <iostream>

namespace yy{
	ThreadPoolThread::ThreadPoolThread(ThreadPool & threadpool)
	:_threadpool(threadpool)
	{
	
	}

	void ThreadPoolThread::run(){
		_threadpool.threadFunc();
	}
}
