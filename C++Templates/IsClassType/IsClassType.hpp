#ifndef ISCLASSTYPE_HPP_
#define ISCLASSTYPE_HPP_

//The differentiation is based on this fact:
//Is valid to construct member pointers when C is a class type.
template<typename T>
class IsClassType
{
private:
	typedef char One;
	typedef struct {char a[2];} Two;

	template<typename C> static One test(int C::*);
	template<typename C> static Two test(...);

public:

	enum { Yes = sizeof(IsClassType<T>::test<T>(0)) == 1 };

	enum { No = !Yes};
};

#endif