 ///
 /// @file    nocopyable.h
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-18 06:40:23
 ///

#ifndef __NOCOPYABLE_H__
#define __NOCOPYABLE_H__

namespace yy{
	class Nocopyable{
		protected:
			Nocopyable(){}
		private:
			Nocopyable(const Nocopyable & rhs);
			Nocopyable & operator =(const Nocopyable & rhs);
	};
}
#endif
