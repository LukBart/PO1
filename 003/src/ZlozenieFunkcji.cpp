#include "ZlozenieFunkcji.h"

void ZlozenieFunkcji::insert (std::function<double(double)> f)
{
	_function.push_back(f);
	_values.push_back (0);
}

double ZlozenieFunkcji::wynik (const double x)
{
	_values[0] = _function[0] (x);
	for (long unsigned i = 1; i < _function.size(); i++)
	{
		_values[i] = _function[i] (_values[i-1]);
	}
	return _values[_values.size() - 1];
}

double ZlozenieFunkcji::operator[] (unsigned i) const
{
	return _values[i];
}