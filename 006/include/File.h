#pragma once

#include "SystemElement.h"

#include <iostream>
#include <vector>
#include <string>

class File : public SystemElement
{
public:
	File (std::string name):
	SystemElement(name){};
	void StreamOfElements (std::ostream& strm, int counter) const;
	
};