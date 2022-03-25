#pragma once

#include <iostream>
#include <cmath>

//klasa-punkt, przechowuje współrzędne i odległopść od środka układu
class FlatPoint
{
public:
//konstruktor zapisujący współrzędne i obliczający odległość od środka układu
	FlatPoint (int x, int y);

//operator porównujący dwa punkty na podstawie odległości od środka układu
	bool operator < (const FlatPoint& other) const;

//metoda drukująca punkty i ich współrzędne na temrinal
	void Print () const;

//metoda statyczna drukująca punkty i ich współrzędne na temrinal
	static void PrintPoint (const FlatPoint& point);

// metoda statyczna drukująca współrzędną Y na temrinal
	static void FunctionPrintY (const FlatPoint& point);

//meotda zwracająca współrzędnąpunktu X
	int GetX () const;

//meotda zwracająca współrzędnąpunktu Y
	int GetY () const;
protected:
	int _x;
	int _y;
	double _distance;
};

//funkcja zwracająca prawdę jeżeli największa wartosć ma współrzędna punktu point2, a fałsz jeżeli największa jest współrzędna punktu point1
bool MaxDistanceAsc (const FlatPoint& point1, const FlatPoint& point2);

//funktor pomagający w sortowniu rosnąco tablicy punktów klasy FlatPoint względem współrzędnej X
struct OrderAscX
{
	bool operator () (const FlatPoint& point1, const FlatPoint& point2) const;
};

//funktor pomagający w sortowaniu malejąco tablicy punktów klasy FlatPoint względem współrzędnej Y
struct OrderDescY 
{
	bool operator () (const FlatPoint& point1, const FlatPoint& point2) const;
};

// procedura drukująca wartośc współrzędnej X na terminal
void FunctionPrintX (const FlatPoint point);