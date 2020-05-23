#ifndef __Student_H__
#define __Student_H__

#include <string>
#include <iostream>

using namespace std;

class Student {

	string imie;
	int indeks;
	
	public:
		Student();
		Student(string imie, int indeks);
		
		friend bool operator < (const Student& s1, const Student& s2);
		friend ostream& operator << (ostream& strumien, const Student& s);
};

#endif
