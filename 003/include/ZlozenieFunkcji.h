#pragma once
#include <iostream>
#include <cmath>
#include <functional>
#include <vector>

class ZlozenieFunkcji
{
public:
//domyślny konstruktor i destruktor
	ZlozenieFunkcji () = default;
	~ZlozenieFunkcji () = default;

//metoda pobierająca std::function i dodająca ją jako ostatnią do złożenia funkcji
//alkouje pamięć na zarówno na funkcjęm jak i wartość kolejnych złożeń funkcji
	void insert (std::function<double(double)> f);

//metoda obliczająca wartości kolejnych złożeń funkcji, zapisuje je w pamięci i zwraca wartość ostateczną
	double wynik (const double x);

//metoda zwraca wartość n-tego złożenia funkcji
	double operator[] (unsigned i) const;
private:
	std::vector<std::function<double(double)>> _function;
	std::vector<double> _values;
};