 ///
 /// @file    buffer.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-19 01:51:07
 ///


#include "buffer.h"
#include <iostream>

namespace yy{
	Buffer::Buffer(int size)
	:_size(size)
	,_mutex()
	,_notempty(_mutex)
	,_notfull(_mutex)

	{
	
	}

	Buffer::~Buffer() {}

	bool Buffer::isempty(){
		return 0 == _que.size();
	}

	bool Buffer::isfull(){
		return _size == _que.size();
	}

	void Buffer::push(int num)
	{
		MutexGuard mg(_mutex);
		while(isfull()){
			_notfull.wait();
		}
			_que.push(num);
			_notempty.notify();
		
	}

	int Buffer::pop(){
		MutexGuard mg(_mutex);
		while(isempty())
			_notempty.wait();
		int num = _que.front();
		_que.pop();
		_notfull.notify();
		return num;
	}
}


