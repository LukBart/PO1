#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "FlatShape.h"

class FSContainer
{
friend std::ostream& operator<< (std::ostream& strm, FSContainer obj);
public:
	FSContainer () = default;

	FSContainer& operator+= (const FlatShape* shape);

private:
	std::vector<const FlatShape*> _v;
};
