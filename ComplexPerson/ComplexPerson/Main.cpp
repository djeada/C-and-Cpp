#include <iostream>
#include <cmath>
#include "CoMPLeX.h"
#include "Person.h"

using namespace std;

int main() {

	CoMPLeX z1(3, -4), z2(2, 5);
	CoMPLeX z3 = 6;
	CoMPLeX sum, diff, prod;

	cout << "z3=" << z3 << endl;			// 6+i*0
	z3 = CoMPLeX(3, -4);
	z3.conjugate();
	cout << "z3=" << z3 << endl;			// 3+i*4
	cout << "|z3|=" << z3.abs() << endl;	// 5

	sum = z1 + z2;	cout << endl << "sum=z1+z2=" << sum;		// 5+i*1
	diff = z1 - z2;	cout << endl << "differnence=z1-z2=" << diff;	// 1-i*9
	prod = z1 * z2;	cout << endl << "product=z1*z2=" << prod;	// 26+i*7

	Person p1("Nowak", 35);
	Person p2("Kowalski", 22);

	cout << endl << p1 << p2 << endl;

	Person data[4] = { Person("Nowak", 35), Person("Nowak", 12), Person("Kowalski", 35), Person("Iksinski", 66) };

	cout << "Before sorting" << endl;
	for (int i = 0; i < 4; i++)
		cout << data[i] << endl;

	Sort_array(data, 4);

	cout << "After sorting" << endl;
	for (int i = 0; i < 4; i++)
		cout << data[i] << endl;

	system("pause");

	return 0;
}
