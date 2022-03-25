#include "MathV.h"

using namespace std;

MathV::MathV (int n) : _size (n), _vector (new double [n]())
{}

MathV::MathV (const MathV &other) : _size (other._size), _vector (new double [other._size])
{
	for (int i = 0; i < _size; i++)
	{
		_vector[i] = other._vector[i];
	}
}

MathV::MathV (MathV &&other)
{
	_size = __exchange (other._size, 0);
	_vector = __exchange (other._vector, nullptr);
}

MathV::~MathV ()
{
	delete [] _vector;
}

double& MathV::at (unsigned int n) const
{
	return _vector[n];
}

void MathV::print (string s) const 
{
	cout << s << "[";
	for (int i = 0; i < _size; i++)
	{
		cout << _vector[i] << ", ";
	} 
	cout << "\b\b]\n";
}

double MathV::dot (const MathV &obj1, const MathV &obj2)
{
	if (obj1._size != obj2._size)
	{
		cout << "Error, vectors of different dimensions!\n";
		return 0;
	}
	double result = 0;
	for (int i = 0; i < obj1._size; i++)
	{
		result += obj1._vector[i] * obj2._vector[i];
	}
	return result;

}

double MathV::norm () const
{
	double result = 0;
	for (int i = 0; i < _size; i++)
	{
		result += pow(_vector[i], 2);
	}
	return sqrt(result);
}

MathV::operator double () const
{
	return this->norm();
}

MathV& MathV::operator+= (const MathV &other)
{
	for (int i = 0; i < _size; i++)
	{
		_vector[i] += other._vector[i];
	}
	return *this;
}

MathV& MathV::operator+= (double n)
{
	for (int i = 0; i < _size; i++)
	{
		_vector[i] += n;
	}
	return *this;
}