#pragma once

#include <iostream>
#include <string>
#include <vector>

class SystemElement
{
	friend std::ostream& operator << (std::ostream& strm, const SystemElement& object);
public:
	SystemElement () = default;
	SystemElement (std::string name):
	_name (name){};
	virtual ~SystemElement (){};
	std::string getName () const;
	virtual void StreamOfElements (std::ostream& strm, int counter) const;
	
protected:
	std::string _name;
};