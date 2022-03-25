#include "Sum.h"

Sum::Sum (Primitive &a, Primitive &b) : _a (a), _b (b)
{}

void Sum::PrintWithValue () const
{
std::cout << "(";
	_a.Print();
	std::cout << "+";
	_b.Print();	
	std::cout << ") = " << _a.Val() + _b.Val() << std::endl;
}

void Sum::Print () const
{
	std::cout << "(";
	_a.Print ();
	std::cout << "+";
	_b.Print ();
	std::cout << ")";
}

double Sum::Val () const
{
	return _a.Val() + _b.Val();
}