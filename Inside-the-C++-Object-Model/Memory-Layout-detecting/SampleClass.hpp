//
// Created by Exia on 2015/8/28.
//

#ifndef MEMORY_LAYOUT_DETECTING_SAMPLECLASS_HPP
#define MEMORY_LAYOUT_DETECTING_SAMPLECLASS_HPP

#include <cstdint>
#include <cstdio>

class SampleClass
{
public:

    SampleClass() : mem_1(0), mem_2(0)
    {}

    virtual int print()
    {
        printf("SampleClass::print.");
        return 0;
    }

public:

    int64_t mem_1;

    int64_t mem_2;

};

#endif //MEMORY_LAYOUT_DETECTING_SAMPLECLASS_HPP
