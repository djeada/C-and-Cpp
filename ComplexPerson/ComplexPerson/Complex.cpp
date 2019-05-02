#include "CoMPLeX.h"
#include <cmath>
#include "Person.h"
#include <string>
using namespace std;

CoMPLeX::CoMPLeX(double re, double im) {
	Re = re;
	Im = im;
}

CoMPLeX::CoMPLeX() {
	Re = 0;
	Im = 0;
}

double CoMPLeX::abs() const {
	double ret = sqrt(Re*Re + Im * Im);
	return ret;
}

ostream& operator<<(ostream & out, const CoMPLeX &a) {
	cout << a.Re << " " << a.Im << "i";
	//cout << a.Re;  cout.showpos <<" "<< a.Im << "i";
	return out;
}

void CoMPLeX::conjugate() {
	Im = -Im;
}

CoMPLeX operator+(const CoMPLeX &a, const CoMPLeX &b) {
	CoMPLeX aC(a.Re + b.Re, a.Im + b.Im);
	return aC;
}

CoMPLeX operator-(const CoMPLeX &a, const CoMPLeX &b) {
	CoMPLeX aC(a.Re - b.Re, a.Im - b.Im);
	return aC;
}

CoMPLeX operator*(const CoMPLeX &a, const CoMPLeX &b) {
	CoMPLeX aC(a.Re*b.Re - a.Im*b.Im, a.Re*b.Im + a.Im*b.Re);
	return aC;
}


//Person functions

Person::Person() {
	name = "";
	age = 0;
}

Person::Person(const string _name, int _age) {
	name = _name;
	age = _age;
}

bool operator<(const Person& p1, const Person& p2) {
	if (p1.age != p2.age)
		return p1.age < p2.age;
	else
		return p1.name < p2.name;
}


ostream& operator<<(ostream &op, const Person &p) {
	op << p.name << " " << p.age << " ";
	return op;
}

void my_swap(Person &a, Person &b) {
	Person p = a;
	a = b;
	b = p;
}

void Sort_array(Person *a, const int size) {
	for (int i = 0; i < (size - 1); i++)
	{
		int min_idx = i;

		// Find the index of the minimum element
		for (int j = i + 1; j < size; j++) {
			if (a[j] < a[min_idx])
			{
				min_idx = j;
			}
		}

		// Swap if i-th element not already smallest
		if (min_idx > i) {
			my_swap(a[i], a[min_idx]);
		}
	}
}
