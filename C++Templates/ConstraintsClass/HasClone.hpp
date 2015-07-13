#ifndef HASCLONE_HPP_
#define HASCLONE_HPP_

//HasClone requires T providing
//T* T::Clone() const
template<typename T>
class HasClone
{
public:
	static void constraints()
	{
		T* (T::*test)() const = &T::clone;

		test;
	}

	HasClone()
	{
		void (*p)() = constraints;
	}
};

#endif