#pragma once

#include  "Primitive.h"
#include <iostream>


//klasa dzieląca dwie liczby przechowywane  w Primitive
class Ratio : public Primitive
{
public:
//konstruktor zapisujacy w pamięci dwa obiekty klasy Primitive
	Ratio (Primitive &a, Primitive &b);

//drukowanie działania z wartością
	void PrintWithValue () const;

//metoda pomocniczna - drukowanie działania
	void Print () const;
	
//zwraca wartość
	double Val () const;

private:
	Primitive& _a;
	Primitive& _b;
};