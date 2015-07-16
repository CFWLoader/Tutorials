#ifndef PROMOTE_HPP_
#define PROMOTE_HPP_

#include "IfThenElse.hpp"

template<typename T1, typename T2>
class Promotion
{
public:
	typedef typename IfThenElse<(sizeof(T1) > sizeof(T2)),
								T1,
								typename IfThenElse<(sizeof(T1) < sizeof(T2)),
													T2,
													void>::ResultType
								>::ResultType ResultType;
};

template<typename T>
class Promotion<T, T>
{
public:
	typedef T ResultType;
};

#endif