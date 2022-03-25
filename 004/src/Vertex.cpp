#include "Vertex.h"

using namespace std;

Vertex::Vertex (int x, int y) : _x (x), _y (y)
{}

int Vertex::getX () const
{
	return _x;
}

int Vertex::getY () const
{
	return _y;
}

std::ostream& operator<< (std::ostream& strm, const Vertex& v)
{
	strm << "<" << v.getX() << ", " << v.getY() << "> ";
	return strm;
}