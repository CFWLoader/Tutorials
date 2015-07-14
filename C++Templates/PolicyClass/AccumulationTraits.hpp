#ifndef ACCUMULATIONTRAITS_HPP_
#define ACCUMULATIONTRAITS_HPP_

//We don't provide every types' template, only the specified types.
template<typename T>
class AccumulationTraits;

//class template specializations.
template<>
class AccumulationTraits<char>
{
public:
	typedef int AccT;

	static AccT zero()
	{
		return 0;
	}
};

template<>
class AccumulationTraits<short>
{
public:
	typedef int AccT;

	static AccT zero()
	{
		return 0;
	}
};

template<>
class AccumulationTraits<int>
{
public:
	typedef long AccT;

	static AccT zero()
	{
		return 0;
	}
};

template<>
class AccumulationTraits<unsigned int>
{
public:
	typedef unsigned long AccT;

	static AccT zero()
	{
		return 0;
	}
};

template<>
class AccumulationTraits<float>
{
public:
	typedef double AccT;

	static AccT zero()
	{
		return 0.0;
	}
};

#endif