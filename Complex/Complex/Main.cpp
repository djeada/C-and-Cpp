#include <iostream>
#include <cmath>

using namespace std;

#include "Complex.h"

int main()
{
	CoMPLX x, y, z, zo;

	cout << "Enter first complex number (C1): ";
	x.Read();
	cout << "Enter second complex number (C2): ";
	y.Read();

	cout << "Your first complex number is (C1): ";
	x.Print();
	cout << endl;
	cout << "Your second complex number is (C2): ";
	y.Print();
	cout << endl << endl;

	z = Add(x, y);
	cout << "Sum of C1 + C2: ";
	z.Print();
	cout << endl;
	cout << "Abs of C1 + C2: " << z.Abs() << endl << endl;

	zo = Add(x, 1);
	cout << "Sum of C1 + (1,0): ";
	zo.Print();
	cout << endl;
	cout << "Abs of C1 + (1,0): " << zo.Abs() << endl << endl;

	const int size = 4;
	CoMPLX tab[size];
	tab[0] = x;
	tab[1] = y;
	tab[2] = z;
	tab[3] = zo;

	cout << "Array of complex numbers is: ";
	for (int i = 0; i < size; i++) {
		tab[i].Print();
		cout << "\t";
	}
	cout << endl;

	cout << "and abs of array: ";
	for (int i = 0; i < size; i++) {
		cout << tab[i].Abs();
		cout << "\t";
	}
	cout << endl;

	Sort_array(tab, size);
	cout << "Sorted array (by abs): ";
	for (int i = 0; i < size; i++) {
		tab[i].Print();
		cout << "\t";
	}
	cout << endl;

	cout << "and abs values: ";
	for (int i = 0; i < size; i++) {
		cout << tab[i].Abs();
		cout << "\t";
	}
	cout << endl;

	system("pause");

	return 0;
}
