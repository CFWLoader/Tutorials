#ifndef TYPEDIFFERENTIATOR_HPP_
#define TYPEDIFFERENTIATOR_HPP_

//Ususally the type isn't a fundamental type.
template<typename T>
class IsFundamentalType
{
public:
	enum{Yes = 0, No = 1};
};

//Specified types
#define makeFundamentalType(T)						\
			template<> class IsFundamentalType<T>	\
			{										\
			public:									\
				enum{Yes = 1, No = 0};				\
			};

makeFundamentalType(void)

makeFundamentalType(bool)
makeFundamentalType(char)
makeFundamentalType(signed char)
makeFundamentalType(unsigned char)
makeFundamentalType(wchar_t)

makeFundamentalType(signed short)
makeFundamentalType(unsigned short)
makeFundamentalType(signed int)
makeFundamentalType(unsigned int)
makeFundamentalType(signed long)
makeFundamentalType(unsigned long)

#if LONGLONG_EXISTS
	makeFundamentalType(signed long long)
	makeFundamentalType(unsigned long long)
#endif

makeFundamentalType(float)
makeFundamentalType(double)
makeFundamentalType(long double)

#undef makeFundamentalType

#endif