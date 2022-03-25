#pragma once

#include <iostream>

class Vertex
{
public:
	Vertex (int x, int y);

	int getX () const;
	int getY () const;

	
private:
	int _x;
	int _y;
};

std::ostream& operator<< (std::ostream& strm, const Vertex& v);