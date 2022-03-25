#pragma once
#include <iostream>
#include <cmath>


class Sinus
{
public:

//konstruktor tworzący funcję sin (a*x + b)
	Sinus (const double a, const double b);

	~Sinus () = default;

//operator () zwracający wartość funkcji sin (a*x + b) dla argumentu x
	const double operator() (const double x) const;
private:
	double _a;
	double _b;
};


class PierwiastekKwadratowy
{
public:
//operator () zwracający wartość funkcji sqrt(x) dla argumentu x
	const double operator () (const double x) const;
};


class Liniowa
{
public:

//konstruktor tworzący funcję liniową a*x + b
	Liniowa (const double a, const double b);

	~Liniowa () = default;

//operator () zwracający wartość funkcji a*x + b dla argumentu x
	const double operator () (const double x) const;

private:

	double _a;

	double _b;
};