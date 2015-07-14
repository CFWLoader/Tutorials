#ifndef ACCUMULATION_HPP_
#define ACCUMULATION_HPP_

#include "AccumulationTraits.hpp"
#include "SumPolicy.hpp"
#include "MultiPolicy.hpp"

template<typename T,
		template<typename, typename> class Policy = SumPolicy,
		typename Traits = AccumulationTraits<T>>
class AccumulationClass
{
public:

	typedef typename Traits::AccT AccT;

	static AccT accumulation(T const* begin, T const* end, const T initialValue)
	{
		AccT total = initialValue;

		while(begin != end)
		{
			Policy<AccT, T>::accumulate(total, *begin);

			++begin;
		}

		return total;
	}
};

template<typename T>
inline typename AccumulationTraits<T>::AccT sum(T const* begin, T const* end)
{
	return AccumulationClass<T>::accumulation(begin, end, 0);
}

template<typename T>
inline typename AccumulationTraits<T>::AccT multiSum(T const* begin, T const* end)
{
	return AccumulationClass<T, MultiPolicy>::accumulation(begin, end, 1);
}

#endif