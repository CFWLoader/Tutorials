#include <iostream>

#include "IsClassType.hpp"

class MyClass{};

struct MyStruct{};

union MyUnion{};

void myFun(){}

enum E{e1}e;

template<typename T>
bool check()
{
	if(IsClassType<T>::Yes)
	{
		std::cout << "Is a class type." << std::endl;

		return true;
	}
	else
	{
		std::cout << "Not a class type." << std::endl;

		return false;
	}
}

template<typename T>
bool checkType(T)
{
	return check<T>();
}

int main(int argc, char* argv[])
{
	using namespace std;

	cout << "int:		";
	check<int>();

	cout << "MyClass:	";
	check<MyClass>();

	cout << "MyStruct:	";
	check<MyStruct>();

	cout << "MyUnion:	";
	check<MyUnion>();

	cout << "enum:		";
	checkType(e);

	cout << "myFun:		";
	checkType(myFun);

	return 0;
}