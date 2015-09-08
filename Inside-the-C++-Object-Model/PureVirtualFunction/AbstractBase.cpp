//
// Created by cfwloader on 9/8/15.
//

#include "AbstractBase.h"

#include <cstring>
#include <iostream>

AbstractBase::AbstractBase(const char* string = "")
{

    mumble_ = new char[::strlen(string) + 1];

    strcpy(mumble_, string);

}

// We have to give a definition to destructor or receipt a comile error.
AbstractBase::~AbstractBase()
{
}

void AbstractBase::interface() const
{
    std::cout << "AbstractBase::interface()" << std::endl;
}

const char* AbstractBase::mumble() const
{
    return mumble_;
}
