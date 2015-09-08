//
// Created by cfwloader on 9/8/15.
//

#include "AbstractBase2.h"

#include <cstring>

AbstractBase2::~AbstractBase2()
{

    delete[] mumble_;

}

AbstractBase2::AbstractBase2(const char *string = "")
{

    mumble_ = new char[strlen(string) + 1];

    strcpy(mumble_, string);

}

const char *AbstractBase2::mumble() const
{
    return mumble_;
}
