#include "Sum.h"

double Sum::value () const
{
	return _value;
}

Sum& Sum::operator() (double n)
{
	_value += n;
	return *this;
}

Sum sumData (const Data& day)
{
	double result = 0;
	for (double d : day.GetValues()){
		result += d;
	}
	Sum sum = Sum();
	(sum)(result);
	return sum;
}