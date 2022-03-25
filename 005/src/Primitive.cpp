#include "Primitive.h"

Primitive::Primitive (double value) : _value (value)
{}

void Primitive::PrintWithValue () const
{}

void Primitive::Set (double value)
{
	_value = value;
}

double Primitive::Val () const
{
	return _value;
}

void Primitive::Print () const
{
	std::cout << _value;
}
