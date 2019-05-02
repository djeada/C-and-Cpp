#include <iostream>
using namespace std;


class CoMPLeX
{
	double Re;
	double Im;
public:
	CoMPLeX();
	CoMPLeX(double re, double im = 0);
	double abs() const;
	void conjugate();

	friend CoMPLeX operator*(const CoMPLeX&, const CoMPLeX&);
	friend CoMPLeX operator-(const CoMPLeX&, const CoMPLeX&);
	friend CoMPLeX operator+(const CoMPLeX&, const CoMPLeX&);

	friend ostream& operator<<(ostream&, const CoMPLeX&);
};