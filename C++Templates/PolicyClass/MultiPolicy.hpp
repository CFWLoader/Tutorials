#ifndef MULTIPOLICY_HPP_
#define MULTIPOLICY_HPP_

template<typename T1, typename T2>
class MultiPolicy
{
public:
	static void accumulate(T1& total, T2 const& value)
	{
		total *= value;
	}
};

#endif