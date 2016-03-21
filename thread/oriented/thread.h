 ///
 /// @file    thread.h
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-18 07:11:18
 ///

#ifndef __THREAD_H__
#define __THREAD_H__

#include "nocopyable.h"
#include <pthread.h>
namespace yy{
	class Thread : private Nocopyable
	{
		public:
			Thread();
			~Thread();
			void start();
			void join();
		private:
			virtual void run() = 0;
			static void * threadfunc(void * arg);
		private:
			pthread_t _phid;
			bool _isRunning;
	};
}

#endif
