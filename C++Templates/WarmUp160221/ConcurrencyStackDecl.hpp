#ifndef CONCURRENCYSTACKDECL_HPP_
#define CONCURRENCYSTACKDECL_HPP_

template<typename ElementType, 
			template<typename ElemType, typename ALLOC = std::allocator<ElemType> > 
				class CONT = std::deque>
class ConcurrencyStack
{
public:

	void push(const ElementType&);

	void pop();

	size_t size();

	bool empty();

	ElementType top();

private:

	CONT<ElementType> container;

};

#endif