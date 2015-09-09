//
// Created by cfwloader on 9/9/15.
//

#ifndef CONSTRUCTORSEMANTICS_CLASSES_H
#define CONSTRUCTORSEMANTICS_CLASSES_H

class Base
{
public:

    Base();

    virtual void function();

private:
};

class Derived : public Base
{
public:

    Derived();

    void function();

private:
};

#endif //CONSTRUCTORSEMANTICS_CLASSES_H
