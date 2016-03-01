#include <iostream>

#include "ConcurrencyStack.hpp"

using namespace std;

int main()
{
	ConcurrencyStack<int> intStack;

	intStack.push(1);

	cout << intStack.size() << endl;

	return 0;
}