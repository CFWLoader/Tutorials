//
// Created by cfwloader on 9/8/15.
//

#include "ConcreteDerived.h"

#include <iostream>

ConcreteDerived::ConcreteDerived(const char* string) : AbstractBase(string)
{ }

ConcreteDerived::~ConcreteDerived()
{
    std::cout << "ConcreteDerived::~ConcreteDerived()" << std::endl;
    delete[] mumble_;
}

void ConcreteDerived::interface() const
{
    //std::cout << "ConcreteDerived::interface()" << std::endl;

    AbstractBase::interface();          // We can invoke a pure virtual function.
}