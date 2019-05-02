#include <iostream>
#include <exception>
#include "Header.h"

using namespace std;

/*
template<typename A>
Image<A> operator+(Image<A> &im1, Image<A> &im2) {
	if (im1.getM() == im2.getM() && im1.getN() == im2.getN()) {
		A* ptr = new A[im1.getM()*im1.getN()];
		for (int i = 0; i < im1.getM()*im1.getN(); i++)
			ptr[i] = im1[i] + im2[i] > im1.ampl ? im1.ampl : im1[i] + im2[i];
		Image<A> ret(im1.getN(), im1.getM(), ptr);
		return ret;
	}
	return Image<A>();
}
*/

int main() {

	int tab[] = { 12,34,99,1,43,22,77,55,23,45,78,98,19,28,37,47 };
	char tabc[] = { 12,34,99,1 };
	try {
		cout << "--------Part 1 (2p)--------" << endl;
		Image<int> i0(4, 4, tab);
		Image<int> i1(i0);
		Image<int> i2;
		i2 = i0;

		cout << "--------Part 2 (1p)--------" << endl;
		cout << i0 << endl << i1 << endl << i2 << endl;

		cout << "--------Part 3 (1p)--------" << endl;
		//uncomment for testing only		
		//Image<short> bad(-1,2);
		//i0[16];

		cout << "--------Part 5 (1p)--------" << endl;

		Image<char> i3(2, 2, tabc);
		Image<char> i4(2, 2, tabc);

		cout << i3 << endl << i4 << endl;

		cout << "--------Part 6 (1p)--------" << endl;
		Image<char> i5 = i3 + i4;
		cout << i5 << endl;

	}
	catch (exception &e) {
		cout << e.what() << endl;
	}

	cout << "Bye" << endl;

	system("pause");
}

