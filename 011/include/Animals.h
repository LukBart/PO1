#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Animal.h"
//klasa przedstawiająca owcę, przechowuje informację czy jest ostrzyżona 
class Sheep : public Animal
{
public:
//konstruktor tworzący obiekt kalsy owca, ktróra nie jest ostzryżona
	Sheep (const std::string &name);
//głośny destruktor
	~Sheep ();
//metoda drukująca na terminal informację o typie, imieniu i ostrzyżeniu
	void print () const;
//metoda strzygąca owcę,zmienia informację o ostrzyżeniu na prawdziwa
	void shear ();
private:
	bool _sheared;
};
//klasa krowy
class Cow : public Animal
{
public:
//konstruktor tworzącoy krowę i imieniu
	Cow (const std::string &name);
//głośny destruktors
	~Cow ();
//metoda drukująca na terminal infgormacje że to krow ao danym iminu
	void print () const;
};
//klasa konia
class Horse : public Animal
{
public:
//konstruktor tworzącyu konia o imienu name
	Horse (const std::string &name);
//głośny destruktor
	~Horse ();
//metoda drukująca informacje że to koń o imieniuu name
	void print () const;
};