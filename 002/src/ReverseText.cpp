#include "ReverseText.h"

ReverseText::ReverseText () : 
_String (nullptr), 
_Next (nullptr)
{}

ReverseText::ReverseText (const char *s) :
_String (new char [strlen (s) + 1]), 
_Next (nullptr)
{
	strcpy (_String, s);
}

ReverseText::ReverseText (const ReverseText &other)
{
	_String = new char [strlen (other._String) + 1];
	strcpy (_String, other._String);
	_Next = other._Next;
}

ReverseText::ReverseText (ReverseText && other) : 
_String (std::__exchange (other._String, nullptr)), 
_Next (std::__exchange (other._Next, nullptr))
{}

ReverseText::~ReverseText ()
{
	ReverseText *element = _Next;
	while (element->_Next != nullptr && element != nullptr)
	{
		if (element->_String != nullptr)
			delete [] element->_String;
		_Next = element->_Next;
		delete element;
		element = _Next;
	}
	if (_String != nullptr){
		delete [] _String;
	}
}

int ReverseText::size (int counter) const
{
	if(_String == nullptr)
	{
		return counter;
	}
	counter += strlen (_String);
	if (_Next == nullptr)
	{
		return counter;
	}
	else
	{
		return _Next->size (counter);
	}
}

int ReverseText::fragments (int counter)
{
	if(_String == nullptr)
	{
		return counter;
	}
	counter ++;
	if (_Next == nullptr)
	{
		return counter;
	}
	else
	{
		return _Next->fragments (counter);
	}
}

int ReverseText::fragments (int counter) const
{
	if(_String == nullptr)
	{
		return counter;
	}
	counter ++;
	if (_Next == nullptr)
	{
		return counter;
	}
	else
	{
		return _Next->fragments (counter);
	}
}

ReverseText& ReverseText::fragment (unsigned i) const
{
	ReverseText* tmp = _Next;
	while (i > 1)
	{
		tmp = tmp->_Next;
		i--;
	}
	return *tmp;
}

char* ReverseText::str () const
{
	return _String;
}

ReverseText& ReverseText::operator-= (const char *s)
{
	ReverseText *element = new ReverseText ();
	element->_String = new char [strlen (_String) + 1];
	strcpy (element->_String, _String);
	element->_Next = _Next;
	_Next = element;
	delete [] _String;
	_String = new char [strlen (s) + 1];
	strcpy (_String, s);
	return *this;
}

ReverseText& ReverseText::operator-= (ReverseText &&other)
{
	_String = std::__exchange(other._String, nullptr);
	_Next = std::__exchange(other._Next, nullptr);
	return *this;
}

ReverseText& ReverseText::operator= (const ReverseText &other)
{
	_Next = other._Next;
	_String = new char [strlen (other._String + 1)];
	strcpy (_String, other._String);
	return *this;
}

ReverseText& ReverseText::operator= (ReverseText &&other)
{
	_String = std::__exchange(other._String, nullptr);
	_Next = std::__exchange(other._Next, nullptr);
	return *this;
}

std::ostream& operator << (std::ostream& strm, const ReverseText &obj)
{
	if (obj._String == nullptr){
		return strm;
	}
	ReverseText const *ptr = &obj;
	while (ptr->_Next != nullptr)
	{
		strm << ptr->_String;
		ptr = ptr->_Next;
	}
	return strm << ptr->_String;
}
