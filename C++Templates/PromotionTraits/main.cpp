#include "PromoteInstances.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
	using namespace std;

	cout << "bool:	" << sizeof(bool) << endl;

	cout << "unsigned char:	" << sizeof(unsigned char) << endl;

	cout << "Their Result type:	" << sizeof(Promotion<bool, unsigned char>::ResultType) << endl;

	return 0;
}