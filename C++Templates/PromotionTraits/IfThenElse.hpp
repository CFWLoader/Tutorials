#ifndef IFTHENELSE_HPP_
#define IFTHENELSE_HPP_

//Determine using T1 or T2 via a boolean value.
template<bool C, typename T1, typename T2>
class IfThenElse;

//Partial Specialization.
template<typename Ta, typename Tb>
class IfThenElse<true, Ta, Tb>
{
public:
	typedef Ta ResultType;
};

template<typename Ta, typename Tb>
class IfThenElse<false, Ta, Tb>
{
public:
	typedef Tb ResultType;
};

#endif