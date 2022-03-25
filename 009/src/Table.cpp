#include "Table.h"
using namespace std;

void Table::operator+= (const Data& data)
{
	if ((int)data.GetValues().size() < minRow)
	{
		minRow = data.GetValues().size();
	}
	_data.push_back(data);
}

void Table::print () const
{
	for_each (_data.begin(), _data.end(), [](const Data& data) {data.print();});
	cout <<endl;
}


Table& Table::sort (int n)
{
	if (n >= minRow)
	{
		cout << "Indeks 3 nieprawidlowy!" << endl;
		return *this;
	}
	std::sort (_data.begin(), _data.end(), [n](Data a, Data b){
		return a.GetValues()[n] < b.GetValues()[n];
	});
	return *this;
}

Table& Table::sortBy (function<bool(const Data&, const Data&)> f)
{
	std::sort (_data.begin(), _data.end(), f);
	return *this;
}