#pragma once

#include  "Primitive.h"
#include <iostream>

//klasa mnożąca dwie liczby przechowywane  w Primitive
class Product : public Primitive
{
public:
//konstruktor zapisujacy w pamięci dwa obiekty klasy Primitive
	Product (Primitive &a, Primitive &b);

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