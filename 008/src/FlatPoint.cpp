#include "FlatPoint.h"

using namespace std;

FlatPoint::FlatPoint (int x, int y) : _x (x), _y (y), _distance (sqrt(pow(x,2) + pow(y, 2))){}

bool FlatPoint::operator < (const FlatPoint& other) const
{
	return _distance < other._distance;
}

void FlatPoint::Print () const
{
	cout << "Point coordinates (" << _x << ", " << _y << ") distance from origin: " << _distance << endl;
}

void FlatPoint::PrintPoint (const FlatPoint& point)
{
	cout << "Point coordinates (" << point._x << ", " << point._y << ") distance from origin: " << point._distance << endl;
}

void FlatPoint::FunctionPrintY (const FlatPoint& point) 
{
	cout << "Function print y=" << point._y << endl;
}

int FlatPoint::GetX () const
{
	return _x;
}

int FlatPoint::GetY () const
{
	return _y;
}

bool MaxDistanceAsc (const FlatPoint& point1, const FlatPoint& point2)
{
	int max1, max2;
	if (point1.GetX () > point1.GetY ())
		max1 = point1.GetX ();
	else
		max1 = point1.GetY ();
	if (point2.GetX () > point2.GetY ())
		max2 = point2.GetX ();
	else
		max2 = point2.GetY ();
	return max1 < max2;
}

bool OrderAscX::operator () (const FlatPoint& point1, const FlatPoint& point2) const
{
	return point1.GetX () < point2.GetX ();
}

bool OrderDescY::operator () (const FlatPoint& point1, const FlatPoint& point2) const
{
	return point1.GetY () > point2.GetY ();
}

void FunctionPrintX (const FlatPoint point)
{
	cout << "Function print x=" << point.GetX () << endl;
}

