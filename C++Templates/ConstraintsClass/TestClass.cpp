#include "TestClass.h"

TestClass* TestClass::clone() const
{
	return new TestClass();
}