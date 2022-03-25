#include "Product.h"

Product::Product (Primitive &a, Primitive &b) : _a (a), _b (b)
{}

void Product::PrintWithValue () const
{
	std::cout << "(";
	_a.Print();
	std::cout << "*";
	_b.Print();
	std::cout << ") = " << _a.Val() * _b.Val() << std::endl;
}

void Product::Print () const
{
	std::cout << "(";
	_a.Print ();
	std::cout << "*";
	_b.Print ();
	std::cout << ")";
}

double Product::Val () const
{
	return _a.Val() * _b.Val();
}