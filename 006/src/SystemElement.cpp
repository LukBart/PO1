#include "SystemElement.h"

using namespace std;

ostream& operator << (ostream& strm, const SystemElement& object)
{
	object.StreamOfElements(strm, 0);
	return strm;
}

string SystemElement::getName () const
{
	return _name;
}

void SystemElement::StreamOfElements (ostream& strm, int counter) const
{
	while (counter-- > 0){
		strm << "  ";
	}
	strm << _name << std::endl;
}