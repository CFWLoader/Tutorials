//
// Created by cfwloader on 9/8/15.
//

#ifndef PUREVIRTUALFUNCTION_ABSTRACTBASE2_H
#define PUREVIRTUALFUNCTION_ABSTRACTBASE2_H

// This is the demonstration.
class AbstractBase2 {
public:

    virtual ~AbstractBase2();

    virtual void interface() = 0;

    const char* mumble() const;

protected:

    AbstractBase2(const char*);

    char* mumble_;

};


#endif //PUREVIRTUALFUNCTION_ABSTRACTBASE2_H
