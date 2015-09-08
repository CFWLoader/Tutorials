//
// Created by cfwloader on 9/8/15.
//

#ifndef PUREVIRTUALFUNCTION_ABSTRACTBASE_H
#define PUREVIRTUALFUNCTION_ABSTRACTBASE_H

// The design of this class is not a good idea.
// See the reasonable one -- AbstractBase2
class AbstractBase
{
public:

    explicit AbstractBase(const char*);

    virtual ~AbstractBase() = 0;                // Destructor should not be pure virtual.

    virtual void interface() const = 0;

    virtual const char* mumble() const;         // This function should not be virtual. The const attribute should be decided by derived class.

protected:                                      // In addition, protected data members disobey the principle of encapsulation.

    char* mumble_;
};


#endif //PUREVIRTUALFUNCTION_ABSTRACTBASE_H
