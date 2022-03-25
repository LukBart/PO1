#include "Ratio.h"

Ratio::Ratio (Primitive &a, Primitive &b) : _a (a), _b (b)
{}

void Ratio::PrintWithValue () const
{
	std::cout << "(";
	_a.Print();
	std::cout << "/";
	_b.Print();
	std::cout << ") = " << _a.Val() / _b.Val() << std::endl;
}

void Ratio::Print () const
{
	std::cout << "(";
	_a.Print ();
	std::cout << "/";
	_b.Print ();
	std::cout << ")";
}

double Ratio::Val () const
{
	return _a.Val() / _b.Val();
}