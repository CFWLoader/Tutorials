#include <iostream>

#include "Classes.hpp"

using namespace std;

int virtualGroup();

int nonVirtualGroup();

/*
 * In this function, I try to visit the virtual table of class C.
 * And function f() is in the virtual table.
 */
int disassembleTheClass();

int main()
{
    virtualGroup();

    nonVirtualGroup();

    disassembleTheClass();

    return 0;
}

int virtualGroup()
{
    cout << "f() is virtual:" << endl;

    A* pointA = new A;
    A* pointB = new B;
    B* pointB1 = new B;
    B* pointC = new C;
    C* pointC1 = new C;

    pointA->f();
    pointB->f();
    pointB1->f();
    pointC->f();
    pointC1->f();

    delete pointA;
    delete pointB;
    delete pointB1;
    delete pointC;
    delete pointC1;
}

int nonVirtualGroup()
{
    cout << "f() is non-virtual:" << endl;

    AnonVir* pointA = new AnonVir;
    AnonVir* pointB = new BnonVir;
    BnonVir* pointB1 = new BnonVir;
    BnonVir* pointC = new CnonVir;
    CnonVir* pointC1 = new CnonVir;

    pointA->f();
    pointB->f();
    pointB1->f();
    pointC->f();
    pointC1->f();

    delete pointA;
    delete pointB;
    delete pointB1;
    delete pointC;
    delete pointC1;
}

int disassembleTheClass()
{
    cout << "Call Virtual function via pointer:" << endl;

    C c;

    char* ptr = (char*)(&c);

    int** vptr = (int**)ptr;

    int** vtbl = (int**)(*vptr);

    typedef int (*FunctionPointer)();

    FunctionPointer fp = (FunctionPointer) vtbl[0];

    fp();
}