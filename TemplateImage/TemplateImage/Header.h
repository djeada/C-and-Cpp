#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
#include <exception>

using namespace std;

template<typename T>
class Image {
	T* data;
	int m, n;
public:
	const static unsigned ampl;
	//Image(T* =nullptr, int x=2, int y=2  );
	Image(int x = 1, int y = 1, T* s = nullptr);
	Image(const Image<T> &);
	Image<T> & operator=(const Image<T> &);
	~Image();
	int getM() const { return m; }
	int getN() const { return n; }
	T& operator[](int i) { if (i > -1 && i < m*n) return data[i]; else throw out_of_range("Out of image"); }

	template <typename A>
	friend ostream& operator<<(ostream &, const Image<A> &);

};

template<typename T>
//Image<T>::Image(T *src, int x, int y ){
Image<T>::Image(int x, int y, T *src) {
	srand((unsigned)time(0));
	if (x > 0 && y > 0) {
		m = x; n = y;
		data = new T[x*y];
		if (src) {
			for (int i = 0; i < x*y; i++)
				if (src[i] > ampl)
					data[i] = ampl;
				else
					data[i] = src[i];
		}
		else {
			for (int i = 0; i < x*y; i++)
				data[i] = ampl * rand() / RAND_MAX;
		}
	}
	else {
		throw invalid_argument("Wrong Image size.");
	}
}

template<typename T>
Image<T>::Image(const Image<T> & im) { //ok
//Image<T>::Image(const Image & im){ //albo tez ok

	m = im.m;
	n = im.n;
	data = new T[m*n];
	for (int i = 0; i < m*n; i++)
		data[i] = im.data[i];

}

template<typename T>
Image<T> & Image<T>::operator=(const Image<T> & im) {
	if (this == &im) return *this;

	m = im.m;
	n = im.n;
	delete[]data;
	data = new T[m*n];
	for (int i = 0; i < m*n; i++)
		data[i] = im.data[i];

	return *this;
}

template<typename T>
Image<T>::~Image() {
	delete[]data;
}

template <typename A>
ostream& operator<<(ostream &os, const Image<A> &im) {
	cout << "image " << im.n << "x" << im.m << endl;
	for (int i = 0; i < im.n; i++) {
		for (int j = 0; j < im.m; j++)
			os << left << setw(3) << (int)im.data[i*im.m + j] << " ";
		os << endl;
	}
	return os;
}

template<>
ostream& operator<<(ostream &os, const Image<char> &im) {
	cout << "image <char>" << im.n << "x" << im.m << endl;
	for (int i = 0; i < im.n; i++) {
		for (int j = 0; j < im.m; j++)
			os << left << setw(3) << (char)('a' + im.data[i*im.m + j]) << " ";
		os << endl;
	}
	return os;
}

template<typename T>
const unsigned int Image<T>::ampl = 255;

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
