#include "FlatShape.h"

using namespace std;

FlatShape::FlatShape (const string s)
{
	_name = s;
	cout << "Jestem nowa figura " << s << endl; 
}

FlatShape& FlatShape::dodajW (const Vertex v)
{
	_v.push_back(v);
	return *this;
}

FlatShape& FlatShape::operator+= (const Vertex v)
{
	return dodajW (v);
}

bool FlatShape::operator== (const FlatShape& other) const
{
	if (_v.size() != other._v.size())
		return false;
	for (int i = 0; i < _v.size(); i++)
	{
		if (_v[i].getX() != other._v[i].getX())
			return false;
		if (_v[i].getY() != other._v[i].getY())
			return false;
	}
	return true;
}

string FlatShape::nazwa () const
{
	return _name;
}

int FlatShape::getSize () const
{
	return _v.size();
}

Vertex FlatShape::getVert (int i) const
{
	return _v[i];
}

std::ostream& operator<< (std::ostream& strm, FlatShape obj)
{
	strm << "Figura " << obj.nazwa() << endl;
	for (int i = 0; i < obj.getSize (); i++)
	{
		strm << obj.getVert(i);
	}
	strm << std::endl;
	return strm;
}
