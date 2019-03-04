#ifndef __Complex_H__
#define __Complex_H__

#include<iostream>
using namespace std;

template<class T>
class Complex {
public:
	T re;
	T im;
public:
	Complex(T _re = 0, T _im = 0) :re(_re), im(_im) {};
	double Abs();
	bool operator> (Complex<T> c);
	template<class T>
	friend Complex<T> operator+(const Complex<T> c1, const Complex<T> c2);
	template<class T>
	friend ostream& operator<< (ostream& out, Complex<T>& c);
};


template<class T>
Complex<T> operator+(const Complex<T> c1, const Complex<T> c2) {
	Complex<T> temp;
	temp.re = c1.re + c2.re;
	temp.im = c1.im + c2.im;
	return temp;
}

template<class T>
double Complex<T>::Abs() {
	return sqrt(re*re + im * im);
}

template<class T>
bool Complex<T>::operator> (Complex<T> c) {
	if (Abs() > c.Abs())
		return true;
	else return false;
}

template<class T>
ostream& operator<< (ostream& out, Complex<T>& c) {
	char sign = '+';
	if (c.im < 0)
		sign = ' ';
	out << c.re << sign << c.im << "i" << endl;
	return out;
}

template<>
ostream& operator<< (ostream& out, Complex<char>& c) {
	char sign = '+';
	if (c.im < 0)
		sign = ' ';
	out << (int)c.re << sign << (int)c.im << "i" << endl;
	return out;
}

#endif