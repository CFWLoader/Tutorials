#ifndef ACCUMULATION_HPP_
#define ACCUMULATION_HPP_

#include "AccumulationTraits.hpp"

template<typename T, typename AT = AccumulationTraits<T>>
class AccumulationClass
{
public:
	static typename AT::AccT accumulation(T const* begin, T const* end)
	{
		typename AT::AccT total = AT::zero();

		while(begin != end)
		{
			total += *begin;

			++begin;
		}

		return total;
	}
};

template<typename T>
inline typename AccumulationTraits<T>::AccT accumulation(T const* begin, T const* end)
{
	return AccumulationClass<T>::accumulation(begin, end);
	/*
	typedef typename AccumulationTraits<T>::AccT AccT;

	AccT total = AccumulationTraits<T>::zero();

	while(begin != end)
	{
		total += *begin;

		++begin;
	}

	return total;
	*/
}

#endif