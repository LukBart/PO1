#include "Funkcje.h"

Sinus::Sinus (const double a, const double b): _a (a), _b (b){}

const double Sinus::operator() (double x) const
{
	return sin (_a * x + _b);
}

const double PierwiastekKwadratowy::operator() (const double x) const
{
	return pow(x, 0.5);
}

Liniowa::Liniowa (const double a, const double b): _a (a), _b (b) {}

const double Liniowa::operator() (const double x) const
{
	return _a * x + _b;
}