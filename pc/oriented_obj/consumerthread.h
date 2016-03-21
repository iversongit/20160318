 ///
 /// @file    consumerthread.h
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-19 03:07:16
 ///

#ifndef __CONSUMERTHREAD_H__
#define __CONSUMERTHREAD_H__

#include "thread.h"

namespace yy{

class Buffer;
class ConsumerThread : public Thread{
	public:
		ConsumerThread(Buffer & buffer)
		:_buffer(buffer)
		{}

		void run();
	private:
		Buffer & _buffer;
};
}

#endif
