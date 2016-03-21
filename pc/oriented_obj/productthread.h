 ///
 /// @file    productthread.h
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-19 02:41:20
 ///

#ifndef __PRODUCTTHREAD_H__
#define __PRODUCTTHREAD_H__
#include "thread.h"

namespace yy{
	class Buffer;
	class ProductThread : public Thread
	{
		public:
			ProductThread(Buffer & buffer);
			void run();
		private:
			Buffer & _buffer;
	};
}

#endif
