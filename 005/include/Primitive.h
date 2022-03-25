#pragma once

#include <iostream>
//klasa przechowująca liczbę całkowitą
class Primitive 
{
public:
	Primitive () = default;
	
//konstruktor nadający wartość przechowywanej liczbie
	Primitive (double value);

	virtual void PrintWithValue () const;

//zmienie wartość przechowywyanej liczby
	void Set (double value);

//drukuje na terminal przechowywaną liczbę
	virtual void Print () const;

//zwraca wartość lcizby
	virtual double Val () const;

protected:
	double _value;
};

