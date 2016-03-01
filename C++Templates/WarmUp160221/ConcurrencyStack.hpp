#ifndef CONCURRENCYSTACK_HPP_
#define CONCURRENCYSTACK_HPP_

#include <deque>

#include "ConcurrencyStackDecl.hpp"
/*
template<typename ElementType, 
			template<typename ElemType, typename ALLOC = std::allocator<ElemType> > 
				class CONT = std::deque>
class ConcurrencyStack
{
public:

	void push(const ElementType&);

	void pop();

	size_t size();

	ElementType top();

private:

	CONT<ElementType> container;

};
*/

template<typename ElementType, template<typename, typename> class CONT>
void ConcurrencyStack<ElementType, CONT>::push(const ElementType& element)
{
	container.push_back(element);
}

template<typename ElementType, template<typename, typename> class CONT>
void ConcurrencyStack<ElementType, CONT>::pop()
{
	container.pop_back();
}

template<typename ElementType, template<typename, typename> class CONT>
size_t ConcurrencyStack<ElementType, CONT>::size()
{
	return container.size();
}

template<typename ElementType, template<typename, typename> class CONT>
bool ConcurrencyStack<ElementType, CONT>::empty()
{
	return container.empty();
}

template<typename ElementType, template<typename, typename> class CONT>
ElementType ConcurrencyStack<ElementType, CONT>::top()
{
	return container.top();
}

#endif