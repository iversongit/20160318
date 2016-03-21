 ///
 /// @file    mutex.h
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-19 00:45:22
 ///

#ifndef __MUTEX_H__
#define __MUTEX_H__

#include "nocopyable.h"
#include <pthread.h>

namespace yy{
	class Mutex : Nocopyable
	{
		public:
			Mutex();
			~Mutex();
			void lock();
			void unlock();
			pthread_mutex_t * getMutex();

		private:
			pthread_mutex_t _mutex;
			bool _islocking;
	};

	class MutexGuard{
		public:
			MutexGuard(Mutex & mutex)
			:_mutex(mutex)
			{
				_mutex.lock();
			}

			~MutexGuard(){
				_mutex.unlock();
			}

		private:
			Mutex & _mutex;
	};
}
#endif
