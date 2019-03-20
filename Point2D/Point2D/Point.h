#ifndef __Point_H__
#define __Point_H__

#include<iostream>
using namespace std;

template <class T>
class Point {
public:
	T x;
	T y;
public:
	Point(T _x = 0, T _y = 0) :x(_x), y(_y) {};
	double Dist();
	bool operator> (Point<T> c);
	template <class T>
	friend Point<T> operator+(const Point<T> c1, const Point<T> c2);
	template <class T>
	friend ostream& operator<< (ostream& out, Point<T>& c);
};

template <class T>
double Point<T>::Dist() {
	return sqrt(x*x + y * y);
}

template <class T>
bool Point<T>::operator> (Point<T> c) {
	if (Dist() > c.Dist())
		return true;
	else return false;
}

template <class T>
Point<T> operator+(const Point<T> c1, const Point<T> c2)
{
	Point<T> temp;
	temp.x = c1.x + c2.x;
	temp.y = c1.y + c2.y;
	return temp;
}

template <class T>
ostream& operator<< (ostream& out, Point<T>& c)
{
	out << "Point with coordinates (" << c.x << " " << c.y << ")" << endl;
	return out;
}

#endif