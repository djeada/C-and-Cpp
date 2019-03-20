#pragma once
#ifndef complx_h
#define complx_h
/*#pragma once*/

class CoMPLX {
private:
	double Re, Im;
public:

	double Abs();
	void Read();
	void Print() const;
	double GetIm() const;
	double GetRe() const;
	void SetRe(double);
	void SetIm(double);
};

CoMPLX Add(CoMPLX &, CoMPLX &);
CoMPLX Add(CoMPLX a, double b);
void swap_p(CoMPLX &a, CoMPLX &b);
void Sort_array(CoMPLX T[], int s);
#endif /*cmplx_h*/
