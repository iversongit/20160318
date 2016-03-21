 ///
 /// @file    condition.h
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-19 01:21:06
 ///


#ifndef __CONDITION_H__
#define __CONDITION_H__

#include "nocopyable.h"
#include <pthread.h>

namespace yy{
class Mutex;
class Condition : Nocopyable
{
	public:
		Condition(Mutex & mutex);
		~Condition();

		void wait();
		void notify();
		void notifyall();
	private:
		pthread_cond_t _cond;
		Mutex & _mutex;
};
}

#endif
