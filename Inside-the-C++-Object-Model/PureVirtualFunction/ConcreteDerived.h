//
// Created by cfwloader on 9/8/15.
//

#ifndef PUREVIRTUALFUNCTION_CONCRETEDERIVED_H
#define PUREVIRTUALFUNCTION_CONCRETEDERIVED_H

#include "AbstractBase.h"


class ConcreteDerived : public AbstractBase
{

public:

    ConcreteDerived(const char*);

    ~ConcreteDerived();

    void interface() const;
};


#endif //PUREVIRTUALFUNCTION_CONCRETEDERIVED_H
