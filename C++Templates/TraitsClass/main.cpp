#include "Accumulation.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
	int number[] = {1, 2, 3, 4, 5};

	char name[] = "templates";

	int length = sizeof(name) - 1;

	std::cout << accumulation(&number[0], &number[5]) << std::endl;

	std::cout << accumulation(&name[0], &name[length]) << std::endl;

	return 0;
}