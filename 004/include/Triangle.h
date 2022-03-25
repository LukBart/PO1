#pragma once

#include "FlatShape.h"

class Triangle : public FlatShape
{
public:
	Triangle (std::string s);

	double pole () const;	

	
};