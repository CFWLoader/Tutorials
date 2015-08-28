#include <iostream>

#include "SampleClass.hpp"

using namespace std;

int main()
{
    printf("mem_1 address: %p.\n", &SampleClass::mem_1);
    printf("mem_2 address: %p.\n", &SampleClass::mem_2);

    printf("member funtion--print address: %p.\n", &SampleClass::print);

    SampleClass sampleClass;

    char* p = (char*)&sampleClass;

    //  Obtaining virtual pointer.
    int** vptr = (int**)p;

    //  Obtaining virtual table of virtual functions via vptr.
    int** vtbl = (int**)(*vptr);

    typedef void (*FunPtr)();

    FunPtr func = (FunPtr) vtbl[0];

    func();

    return 0;
}