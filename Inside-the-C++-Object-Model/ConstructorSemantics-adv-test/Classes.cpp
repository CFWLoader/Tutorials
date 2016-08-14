//
// Created by cfwloader on 9/9/15.
//

#include <iostream>
#include "Classes.h"

Base::Base() : initializationCounter(0)
{
    function();
}

void Base::function()
{
    ++initializationCounter;

    std::cout << "Base::function(), X:function() is called " << initializationCounter << " in this object." << std::endl;
}

void Derived::function()
{
    ++initializationCounter;

    std::cout << "Derived::function(),  X:function() is called " << initializationCounter << " in this object." << std::endl;
}

Derived::Derived()
{
    function();
}
