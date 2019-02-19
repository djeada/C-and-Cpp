#include <iostream>
#include <cmath>
#include "Complex.h"

double CoMPLX::Abs() {
	return (sqrt(Re * Re + Im * Im));
}

void CoMPLX::Read() {
	std::cin >> Re >> Im;
}

void CoMPLX::Print() const {
	std::cout << Re << "+" << Im << "i";
}

double CoMPLX::GetIm() const {
	return Im;
}

double CoMPLX::GetRe() const {
	return Re;
}

void CoMPLX::SetIm(double x) {
	Im = x;
}

void CoMPLX::SetRe(double x) {
	Re = x;
}

CoMPLX Add(CoMPLX &x, CoMPLX &y) {
	CoMPLX z;
	z.SetRe(x.GetRe() + y.GetRe());
	z.SetIm(x.GetIm() + y.GetIm());
	return z;
}

CoMPLX Add(CoMPLX a, double b) {
	CoMPLX z;
	z.SetRe(a.GetRe() + b);
	z.SetIm(a.GetIm());
	return z;
}

void Sort_array(CoMPLX T[], int s) {
	for (int i = 0; i < (s - 1); i++)
	{
		int min_idx = i;

		// Find the index of the minimum element
		for (int j = i + 1; j < s; j++)
		{
			if (T[j].Abs() < T[min_idx].Abs())
			{
				min_idx = j;
			}
		}

		// Swap if i-th element not already smallest
		if (min_idx > i)
		{
			swap_p(T[i], T[min_idx]);
		}
	}
}

void swap_p(CoMPLX &a, CoMPLX &b) {
	CoMPLX tmp;
	tmp = a;
	a = b;
	b = tmp;
}

