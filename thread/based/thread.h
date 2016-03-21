 ///
 /// @file    thread.h
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-18 07:11:18
 ///

#ifndef __THREAD_H__
#define __THREAD_H__

#include "nocopyable.h"
#include <pthread.h>
#include <functional>
namespace yy{
	class Thread : private Nocopyable
	{
		public:
			typedef std::function<void()> ThreadCallback;
			Thread(ThreadCallback cb);
			~Thread();
			void start();
			void join();
		private:
			static void * threadfunc(void * arg);
		private:
			pthread_t _phid;
			bool _isRunning;
			ThreadCallback _cb;
	};
}

#endif
