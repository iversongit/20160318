 ///
 /// @file    thread.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-18 07:17:14
 ///

#include "nocopyable.h"
#include "thread.h"
#include <iostream>
using std::cout;
using std::endl;

namespace yy{
	Thread::Thread(ThreadCallback cb)
	:_phid(0)
	,_isRunning(false)
	,_cb(cb)
	{
		cout<<"Thread()"<<endl;
	}

	Thread::~Thread(){
		if(_isRunning)
			pthread_detach(_phid);
	}

	void Thread::start(){
		pthread_create(&_phid,NULL,&Thread::threadfunc,this);
		_isRunning = true;
	}

	void Thread::join(){
		if(_isRunning)
			pthread_join(_phid,NULL);
	}

	void * Thread::threadfunc(void * arg){
		Thread * thread = static_cast<Thread *>(arg);
		if(thread)
			thread->_cb();
	}
}
