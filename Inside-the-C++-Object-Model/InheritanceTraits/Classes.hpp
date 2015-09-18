//
// Created by cfwloader on 9/18/15.
//

#ifndef INHERITANCETRAITS_CLASSES_HPP
#define INHERITANCETRAITS_CLASSES_HPP

#include <stdio.h>

/* This group use virtual function in inheritance.
 * For comparison of the C::f is virtual or not, setting another group which f is non-virtual.
 */
class A
{
public:
    virtual void f()
    {
        printf("A::f()\n");
    }
};

class B : public A
{
public:
    void f()
    {
        printf("B::f()\n");
    }
};

class C : public B
{
public:
    void f()
    {
        printf("C::f()\n");
    }
};

/*
 * In this group, f is non-virtual.
 */
class AnonVir
{
public:
    void f()
    {
        printf("A::f()\n");
    }
};

class BnonVir : public AnonVir
{
public:
    void f()
    {
        printf("B::f()\n");
    }
};

class CnonVir : public BnonVir
{
public:
    void f()
    {
        printf("C::f()\n");
    }
};

#endif //INHERITANCETRAITS_CLASSES_HPP
