#pragma once

#include <iostream>
using namespace std;

//klasa szablonowa, kontener na parę liczb różnego typu
template<typename T1, typename T2>
class PairOfNumbers
{
public:
	T1& first;
	T2& second;
	PairOfNumbers (T1& n1, T2& n2): first (n1), second (n2) {}

	PairOfNumbers <T2, T1> Swapped () const
	{
	return PairOfNumbers <T2,T1> (second, first);
	}
	~PairOfNumbers () = default;
	void Print () const
	{
	cout << "Print method: " << first << " " << second << endl;
	}

	void Add (int n)
	{
	first += (T1)n;
	second += (T2)n;
	}

	void Scale (int n)
	{
	first *= (T1)n;
	second *= (T2)n;
	}

	void Info ()
	{
	cout << "This is NON-const pair of numbers\n";
	}

	void Info () const
	{
	cout << "This is const pair of numbers\n";
	}

};