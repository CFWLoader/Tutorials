#ifndef PSEUDOCOMPONENT_H_
#define PSEUDOCOMPONENT_H_

#include "HasClone.hpp"

//This class is to simulate a template component that requires the template instance has the clone() member function.
template<typename T>
class PseudoComponent : HasClone<T>
{
public:
private:
};

#endif