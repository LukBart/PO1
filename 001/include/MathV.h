#pragma once
#include <iostream>
#include <cmath>

class MathV
{
public:
	MathV () = default;

//alokuje pamięc na wektor o długości n i wypełnia ją zerami
	explicit MathV (int n);

//alokuje pamięć i kopiuje zawartość obiektu other
	MathV (const MathV &other);

//przenosi zawartość z konstruktora other
//po całej procedurze obiekt znika z pamięci
	MathV (MathV &&other);

//zwalnia pamięć zaalokowaną przez wektor
	~MathV ();

//zwraca wskaźnik na n-ty element wektora
//pozwala na przypisanie wartości danemu elementowi
	double& at (unsigned int n) const;

//drukuje w terminalu wektor, który poprzedza stringiem s
	void print (std::string s) const;

//zwraca iloczyn skalarny wektorów 
	static double dot (const MathV &obj1, const MathV &obj2);

//zwraca normę wektora
	double norm () const;

//zwraca normę wektora
	operator double () const;

//pozwala na dodanie do siebie dwóch wektorów
	MathV& operator+= (const MathV &other);

//dodaje wartość n do każdej składowej wektora
	MathV& operator+= (double n);
private:
	int _size;
	double *_vector;
};