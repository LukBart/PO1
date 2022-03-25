#include "Data.h"

using namespace std;

Data::Data (std::string day, std::vector<double> values) : _day (day), _values (values) {}

void Data::print () const
{
	cout << _day << ": ";
	for_each (_values.begin(), _values.end(),[](double n) {cout << setw (6) << n;});
	cout << endl;
}

vector<double> Data::GetValues () const
{
	return _values;
}