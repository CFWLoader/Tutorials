#include <iostream>

#include "SampleClass.hpp"

using namespace std;

int simpleTest();

int MI_Test();

int main()
{
    return MI_Test();
}

int simpleTest()
{
    printf("mem_1 address: %p.\n", &SampleClass::mem_1);
    printf("mem_2 address: %p.\n", &SampleClass::mem_2);

    printf("member funtion--print address: %p.\n", &SampleClass::print);

    SampleClass sampleClass;

    char *p = (char *) &sampleClass;

    //  Obtaining virtual pointer.
    int **vptr = (int **) p;

    //  Obtaining virtual table of virtual functions via vptr.
    int **vtbl = (int **) (*vptr);

    typedef void (*FunPtr)();

    FunPtr func = (FunPtr) vtbl[0];

    printf("member funtion--print address: %p.\n", vtbl[0]);

    func();

    return 0;
}

int MI_Test()
{
    Derived d;
    char *p = (char *) &d;
    visitVtbl((int **) *(int **) p, 3);
    p += sizeof(int **);

    cout << *(int64_t *) p << endl;
    p += sizeof(int64_t);

    visitVtbl((int **) *(int **) p, 3);
    p += sizeof(int **);

    cout << *(int64_t *) p << endl;
    p += sizeof(int64_t);

    cout << *(int *) p << endl;

    return 0;
}