 ///
 /// @file    threadpoolthread.h
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-21 01:05:14
 ///

#ifndef __THREADPOOLTHREAD_H__
#define __THREADPOOLTHREAD_H__

#include "thread.h"
#include <iostream>

namespace yy{
	class ThreadPool;
	class ThreadPoolThread : public Thread{
		public:
			ThreadPoolThread(ThreadPool & threadpool);
			void run();
		private:
			ThreadPool & _threadpool;
	};
}

#endif
