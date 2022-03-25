#pragma once

#include <iostream>
#include "PairOfNumbers.h"

template<typename T>
class RangeArray
{
public:
	RangeArray (PairOfNumbers <int, T> pair)
	: _size (pair.second - pair.first)
	{
	_array = new T[_size];
	}
	RangeArray (const RangeArray& other)
	{
		_size = other._size;
		_array = new T[_size];
		for (int i = 0; i < _size; i++)
		{
			_array[i] = other._array[i];
		}
	}
	~RangeArray ()
	{
		delete [] _array;
	}
	
	int Size () const
	{
	return _size;
	}


	T& operator[] (int n)
	{
	while (n < 0)
	{
		n +=_size;
	}
	return _array[n];
	}

	T& At (int n)
	{
	while (n < 0)
	{
		n +=_size;
	}
	return _array[n];
}
private:
	int _size;
	T* _array;
};