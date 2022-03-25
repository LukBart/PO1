#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <iomanip>
#include <algorithm>

#include "Data.h"

class Table
{
public:
	Table () = default;
	void operator += (const Data& data);
	int minRow = 5000;
	void print () const;
	Table& sort (int n);
	Table& sortBy (std::function<bool(const Data&, const Data&)> f);
private:
	std::vector<Data> _data;
};