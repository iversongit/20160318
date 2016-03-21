 ///
 /// @file    condition.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-19 01:31:57
 ///

#include "condition.h"
#include "mutex.h"
#include <iostream>

namespace yy{
Condition::Condition(Mutex & mutex)
:_mutex(mutex)
{
	pthread_cond_init(&_cond,NULL);
}

Condition::~Condition(){
	pthread_cond_destroy(&_cond);
}

void Condition::wait(){
	pthread_cond_wait(&_cond,_mutex.getMutex());
}

void Condition::notify(){
	pthread_cond_signal(&_cond);
}

void Condition::notifyall(){
	pthread_cond_broadcast(&_cond);
}
}
