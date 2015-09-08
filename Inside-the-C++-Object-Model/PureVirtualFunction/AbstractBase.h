//
// Created by cfwloader on 9/8/15.
//

#ifndef PUREVIRTUALFUNCTION_ABSTRACTBASE_H
#define PUREVIRTUALFUNCTION_ABSTRACTBASE_H


class AbstractBase
{
public:

    explicit AbstractBase(const char*);

    virtual ~AbstractBase() = 0;

    virtual void interface() const = 0;

    virtual const char* mumble() const;

protected:

    char* mumble_;
};


#endif //PUREVIRTUALFUNCTION_ABSTRACTBASE_H
