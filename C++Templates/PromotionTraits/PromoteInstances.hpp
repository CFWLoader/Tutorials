#ifndef PROMOTEINSTANCES_HPP_
#define PROMOTEINSTANCES_HPP_

#include "Promote.hpp"

#define MakePromotion(T1, T2, Tr)						\
			template<> class Promotion<T1, T2> {		\
				public:									\
					typedef Tr ResultType;				\
			};											\
														\
			template<> class Promotion<T2, T1> {		\
				public:									\
					typedef Tr ResultType;				\
			};

//You have to specify the promotion rules dully.
MakePromotion(bool, char, int)

MakePromotion(bool, unsigned char, int)

MakePromotion(bool, signed char, int)

#endif