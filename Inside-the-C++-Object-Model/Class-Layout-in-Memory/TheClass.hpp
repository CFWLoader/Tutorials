//
// Created by Exia on 2015/8/28.
//

#ifndef CLASS_LAYOUT_IN_MEMORY_THECLASS_HPP
#define CLASS_LAYOUT_IN_MEMORY_THECLASS_HPP

#pragma once
#include<iostream>

#include "ClassRecorder.hpp"

using namespace std;
class Base
{
public:
    Base(int)
    { }

    virtual ~Base(void)
    { }

    int getIBase() const
    { }

    static int instanceCount()
    { }

    virtual void print() const
    { }

protected:

    int iBase;
    static int count;
};

void test_base_model()
{
    Base b1(1000);
    cout << "对象b1的起始内存地址：" << &b1 << endl;
    cout << "type_info信息：" << ((int*)*(int*)(&b1) - 1) << endl;
    RTTICompleteObjectLocator str=
            *((RTTICompleteObjectLocator*)*((int*)*(int*)(&b1) - 1));
    //abstract class name from RTTI
    std::string classname(str.pTypeDescriptor->name);
    classname = classname.substr(4,classname.find("@@")-4);
    cout << classname <<endl;
    cout << "虚函数表地址：\t\t\t" << (int*)(&b1) << endl;
    cout << "虚函数表 — 第1个函数地址：\t" << (int*)*(int*)(&b1) << "\tBase::print()：" << (int*)*((int*)*(int*)(&b1)) << endl;
    //cout << "虚函数表 — 第2个函数地址：\t" << ((int*)*(int*)(&b1) + 1) << "\t";
    typedef void(*Fun)(void);
    Fun pFun = (Fun)*(((int*)*(int*)(&b1)) + 1);
    pFun();
    b1.print();
    cout << endl;
    cout << "推测数据成员iBase地址：\t\t" << ((int*)(&b1) +1) << "\t通过地址取值iBase的值：" << *((int*)(&b1) +1) << endl;
    cout << "Base::getIBase(): " << b1.getIBase() << endl;

    b1.instanceCount();
    cout << "静态函数instanceCount地址： " << b1.instanceCount << endl;
}

#endif //CLASS_LAYOUT_IN_MEMORY_THECLASS_HPP
