#ifndef CONCURRENCYSTACK_HPP_
#define CONCURRENCYSTACK_HPP_

#include <deque>

template<typename ElementType, 
			template<typename ElemType, typename ALLOC = std::allocator<ElemType> > 
				class CONT = std::deque>
class ConcurrencyStack
{
public:
private:
};

#endif