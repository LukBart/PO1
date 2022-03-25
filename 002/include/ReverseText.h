#pragma once

#include <iostream>
#include <cstring>

class ReverseText
{
	friend std::ostream& operator<< (std::ostream &strm, const ReverseText &obj);
public:
	ReverseText ();
	ReverseText (const char *s);
	ReverseText (const ReverseText &other);
	ReverseText (ReverseText &&other);
	~ReverseText ();

	int size (int counter = 0) const;
	int fragments (int counter = 0);
	int fragments (int counter = 1) const;
	ReverseText& fragment (unsigned i) const;
	char* str () const;	
	
	ReverseText& operator-= (const char* s);
	ReverseText& operator-= (ReverseText &&other);
	
	ReverseText& operator= (const ReverseText &other);
	ReverseText& operator= (ReverseText &&other);
private:
	char *_String;
	ReverseText *_Next;

};

	// std::cout << "1\n";
