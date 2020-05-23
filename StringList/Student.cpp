#include "Student.h"

Student::Student(){
	imie = "imie";
	indeks = 0;
}

Student::Student(string _imie, int _indeks){
	imie = _imie;
	indeks = _indeks;
}


bool operator < (const Student& s1, const Student& s2){
	return s1.imie < s2.imie;
}


ostream& operator << (ostream& strumien, const Student& s){
	cout << "Imie studenta: " << s.imie << endl;
	cout << "Numer indeksu: " << s.indeks << endl;
	return strumien;
}
