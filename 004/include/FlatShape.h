#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Vertex.h"

class FlatShape 
{
public:
	FlatShape () = default;
	FlatShape (const std::string s);

	FlatShape& dodajW (const Vertex v);
	
	FlatShape& operator+= (const Vertex v);

	bool operator== (const FlatShape& other) const;

	std::string nazwa () const;

	int getSize () const;

	Vertex getVert (int i) const;
private:
	std::string _name;
	std::vector<Vertex> _v;
};

std::ostream& operator<< (std::ostream& strm, FlatShape obj);



