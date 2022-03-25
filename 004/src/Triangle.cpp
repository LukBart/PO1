#include "Triangle.h"

using namespace std;

Triangle::Triangle (std::string s)
{
	// _name = s;
	cout << "Jestem nowa figura " << s << endl << "Mowiac scisle, jestem trojkatem." << endl;
}

double Triangle::pole () const
{
	return (getVert(0).getX()- getVert (1).getX())*(getVert (1).getY() - getVert (2).getY())/2.0;
}