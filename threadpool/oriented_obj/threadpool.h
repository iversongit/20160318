 ///
 /// @file    threadpool.h
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-20 04:58:43
 ///

#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__

#include "buffer.h"
#include <vector>

using std::vector;

namespace yy{
	class Task;
	class Thread;
	class ThreadPool{
		public:
			ThreadPool(int threadnum,int bufsize);
			~ThreadPool();

			void start();
			void stop();

			void addTask(Task * task);
			void threadFunc();
		private:
			Task * getTask();

		private:
			int _threadnum;
			vector<Thread *> _vecThreads;
			int _bufsize;
			Buffer _buffer;
			bool _isExit;
	};
}

#endif
