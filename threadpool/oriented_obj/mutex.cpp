 ///
 /// @file    mutex.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-19 01:10:51
 ///

#include "mutex.h"
#include <iostream>

namespace yy{
	Mutex::Mutex()
	:_islocking(false)
	{
		pthread_mutex_init(&_mutex,NULL);
	}

	Mutex::~Mutex(){
		pthread_mutex_destroy(&_mutex);
	}

	void Mutex::lock(){
		pthread_mutex_lock(&_mutex);
		_islocking = true;
	}

	void Mutex::unlock(){
		pthread_mutex_unlock(&_mutex);
		_islocking = false;
	}

	pthread_mutex_t * Mutex::getMutex(){
		return &_mutex;
	}

}
