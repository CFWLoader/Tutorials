#include <iostream>

#include "TypeDifferentiator.hpp"

template<typename T>
void test(T const& t)
{
	std::cout << __func__ << std::endl;									//Display the function name.

	if(IsFundamentalType<T>::Yes)
	{
		std::cout << "T is fundamental type." << std::endl;
	}
	else
	{
		std::cout << "T is not fundamental type." << std::endl;
	}
}

class MyType{};

int main(int argc, char* argv[])
{

	test(7);

	test(MyType());

	return 0;
}