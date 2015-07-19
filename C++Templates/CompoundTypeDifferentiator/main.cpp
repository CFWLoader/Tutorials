#include "CompoundType.hpp"

#include <iostream>

auto testPostReturnType() -> int 												//C++ 11 new traits : Post return type declaration.
{																				//It will be more powerful if be teamed with decltype keyword and template.
	return 3;
}

template<typename T, typename U>
auto testPostReturnType(T a, U b) -> decltype(a * b)							//Combine with template and decltype.
{
	return a * b;
}

int main(int argc, char* argv[])
{
	using namespace std;

	int* arr;

	cout << CompoundType<decltype(arr)>::IsPointerType << endl;					//Here uesd c++ 11 new key word -- decltype.

	cout << testPostReturnType() << endl;										//Here uesd c++ 11 new key word -- decltype.

	cout << testPostReturnType(11, 3.55) << endl;								//Here uesd c++ 11 new key word -- decltype.

	return 0;
}