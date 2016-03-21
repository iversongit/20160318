 ///
 /// @file    buffer.h
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-19 01:45:18
 ///

#ifndef __BUFFER_H__
#define __BUFFER_H__

#include "mutex.h"
#include "condition.h"
#include <queue>

namespace yy{
	class Buffer
	{
		public:
			Buffer(int size);
			~Buffer();

			void push(int num);
			int pop();

			bool isempty();
			bool isfull();
		private:
			int _size;
			std::queue<int> _que;
			Mutex _mutex;
			Condition _notempty;
			Condition _notfull;
	};
}

#endif
