#include<iostream>
#include "Complex.h"
#include "Point.h"
using namespace std;

template<typename T, int N>
void sort(T(&a)[N])
{
	cout << "sort" << endl;
	for (unsigned int i = 0; i < N - 1; ++i)
		for (unsigned int j = i + 1; j < N; ++j)
		{
			if (a[i] > a[j])
			{
				T tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
}

int main()
{
	Complex<char> c1, c2(1, 4), c3;
	cout << c1;
	cout << c2;
	c3 = c1 + c2;
	cout << c3;
	if (c3 > c2)
		cout << "True\n";
	else cout << "False\n";
	Point<double> p1(1), p2(4, 5), p3;
	cout << p1;
	cout << p2;
	p3 = p1 + p2;
	cout << p3;
	if (p3 > p2)
		cout << "True\n";
	else cout << "False\n";
	Complex<int> tab1[] = { Complex<int>(1, 2), Complex<int>(3, 2), Complex<int>(1, 1) };
	Point<double> tab2[] = { Point<double>(-1., 2.), Point<double>(-2, 2), Point<double>(4, 0) };

	sort<Complex<int>, 3>(tab1);
	sort(tab2);

	cout << "Cpx2d" << endl;
	for (int i = 0; i < sizeof(tab1) / sizeof(Complex<int>); i++) {
		cout << tab1[i].re << "+i" << tab1[i].im << endl;
	}
	cout << "Point2d" << endl;
	for (int i = 0; i < sizeof(tab2) / sizeof(Point<double>); i++) {
		cout << tab2[i].x << " " << tab2[i].y << endl;
	}

	cout << "bye" << endl;

	system("pause");
	return 0;
}
