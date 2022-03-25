#pragma once

#include "SystemElement.h"

#include <iostream>
#include <vector>
#include <string>

class Dir final : public SystemElement
{
public:
	Dir (std::string name):
	SystemElement (name) {};
	~Dir ();
	Dir& operator += (SystemElement* other);

	Dir* findDir (std::string name);

	void add (SystemElement* other);

	SystemElement* get (std::string name);
	
	void StreamOfElements (std::ostream& strm, int counter) const override;

private:
	std::vector <SystemElement*> _content;
};
