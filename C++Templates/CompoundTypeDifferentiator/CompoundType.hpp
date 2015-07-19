#ifndef COMPOUNDTYPE_HPP_
#define COMPOUNDTYPE_HPP_

#include <cstddef>

//Basic template.
template<typename T>
class CompoundType
{
public:
	enum{IsPointerType = 0, IsReferenceType = 0, IsArrayType = 0,
			IsFunctionType = 0, IsPointerMemberType = 0};

	typedef T BaseType;
	typedef T BottomType;
	typedef CompoundType<void> ClassType;
};

//Partial Specializtion of reference.
template<typename T>
class CompoundType<T&>
{
public:
	enum{IsPointerType = 0, IsReferenceType = 1, IsArrayType = 0,
			IsFunctionType = 0, IsPointerMemberType = 0};

	typedef T BaseType;
	typedef typename CompoundType<T>::BottomType BottomType;
	typedef CompoundType<void> ClassType;
};

//Partial Specializtion of pointer.
template<typename T>
class CompoundType<T*>
{
public:
	enum{IsPointerType = 1, IsReferenceType = 0, IsArrayType = 0,
			IsFunctionType = 0, IsPointerMemberType = 0};

	typedef T BaseType;
	typedef typename CompoundType<T>::BottomType BottomType;
	typedef CompoundType<void> ClassType;
};

//Partial Specializtion of Array.
template<typename T, size_t N>
class CompoundType<T[N]>
{
public:
	enum{IsPointerType = 0, IsReferenceType = 0, IsArrayType = 1,
			IsFunctionType = 0, IsPointerMemberType = 0};

	typedef T BaseType;
	typedef typename CompoundType<T>::BottomType BottomType;
	typedef CompoundType<void> ClassType;
};

//Partial Specializtion of Empty Array.
template<typename T>
class CompoundType<T[]>
{
public:
	enum{IsPointerType = 0, IsReferenceType = 0, IsArrayType = 1,
			IsFunctionType = 0, IsPointerMemberType = 0};

	typedef T BaseType;
	typedef typename CompoundType<T>::BottomType BottomType;
	typedef CompoundType<void> ClassType;
};

//Partial Specializtion of member pointer.
template<typename T, typename C>
class CompoundType<T C::*>
{
public:
	enum{IsPointerType = 0, IsReferenceType = 0, IsArrayType = 0,
			IsFunctionType = 0, IsPointerMemberType = 1};

	typedef T BaseType;
	typedef typename CompoundType<T>::BottomType BottomType;
	typedef C ClassType;
};

#endif