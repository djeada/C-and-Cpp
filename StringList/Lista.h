#ifndef __Lista_H__
#define __LIsta_H__

#include <iostream>
#include "Student.h"

using namespace std;

class Wezel {
	Student nasz_student;
	Wezel* nastepny;
	public:
		Wezel(Student s){
			nasz_student = s;
			nastepny = nullptr;
		}
		
		void ustawStudenta(Student s){
			nasz_student = s;
		}
		
		Student getStudent(){
			return nasz_student;
		}
		
		void ustawStrzalke(Wezel* strzalka){
			nastepny = strzalka;
		}
		
		Wezel* getNastepny(){
			return nastepny;
		}
};

class Lista {
	Wezel* glowa;
	
	public:
		Lista(Student s);
		~Lista();
		
		void wstaw(Student s);
		
		friend ostream& operator << (ostream& strumien, const Lista& l);

};

#endif
