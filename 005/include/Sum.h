#pragma once

#include  "Primitive.h"
#include <iostream>


//klasa dodająca dwie liczby przechowywane  w Primitive
class Sum : public Primitive
{
public:
//konstruktor zapisujacy w pamięci dwa obiekty klasy Primitive
	Sum (Primitive &a, Primitive &b);

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