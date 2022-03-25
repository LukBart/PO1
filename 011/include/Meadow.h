#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include "Animal.h"
#include "Animals.h"

//kalsa przechowująca wektor zwierząt
class Meadow
{
public:
	Meadow () = default;
	~Meadow ();
//metoda dodająca zwierze do wektora
	void add (std::unique_ptr<Animal> animal);
//mertoda drukująca string s i zwierzęta na łące
	void print (const std::string s) const;
//metoda licząca zwierzęta o danym imienu
	void countNames () const;
//metoda zwracająca wektro owiec
	std::vector<Sheep*> getSheepHerd ();
private:
	std::vector<std::unique_ptr<Animal>> _herd;
};