#ifndef ACCUMULATION_HPP_
#define ACCUMULATION_HPP_

#include "AccumulationTraits.hpp"

template<typename T>
inline typename AccumulationTraits<T>::AccT accumulation(T const* begin, T const* end)
{
	typedef typename AccumulationTraits<T>::AccT AccT;

	AccT total = AccT();

	while(begin != end)
	{
		total += *begin;

		++begin;
	}

	return total;
}

#endif