#pragma once

#include <iostream>
#include <algorithm>
#include "Data.h"

class Sum
{
public:
	Sum () = default;
	double value () const;
	Sum& operator() (double n);
private:
	double _value;
};

Sum sumData (const Data& day);