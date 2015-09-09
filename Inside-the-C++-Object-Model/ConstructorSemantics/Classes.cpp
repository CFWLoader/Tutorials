//
// Created by cfwloader on 9/9/15.
//

#include <iostream>
#include "Classes.h"

Base::Base()
{
    function();
}

void Base::function()
{
    std::cout << "Base::function()" << std::endl;
}

void Derived::function()
{
    std::cout << "Derived::function()" << std::endl;
}

Derived::Derived()
{
    function();
}
