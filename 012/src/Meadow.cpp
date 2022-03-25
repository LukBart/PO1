#include "Meadow.h"

using namespace std;

Meadow::~Meadow ()
{

}

void Meadow::add (std::unique_ptr<Animal> animal)
{
	_herd.push_back (move(animal));
}

void Meadow::print(const string s) const
{
	cout << "=== " << s << " ===" << endl;
	for (const auto &v: _herd)
	{
		v->print ();
	}
}

void Meadow::countNames () const
{
	vector<string> names;
	names.push_back (_herd[0]->name());
	for (const auto &name: _herd)
	{
		bool b = false;
		for (const string n: names)
		{
			if (name->name() == n)
			{
				b = true;
			}
		}
		if (b == false)
			names.push_back (name->name());
	}
	sort (names.begin(), names.end());
	for (const string n: names)
	{
		cout << n << ": ";
		int i = 0;
		for (const auto &name: _herd)
		{
			if (name->name () == n)
				i++;
		}
		cout << i << endl;
	}
}

vector<Sheep*> Meadow::getSheepHerd ()
{
	std::vector<Sheep*> sheepHerd; 
	for (const auto &v : _herd)
	{
		Sheep* e;
		if ((e = dynamic_cast<Sheep*> (v.get()))){
			sheepHerd.push_back(e);
		}
	}

	return sheepHerd;
}

