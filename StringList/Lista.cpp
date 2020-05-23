#include "Lista.h"

Lista::Lista(Student s){
	glowa = new Wezel(s);
}


Lista::~Lista(){
	Wezel* oczyszczacz = glowa;
	
	while(oczyszczacz != nullptr){
		glowa = glowa->getNastepny();
		delete oczyszczacz;
		oczyszczacz = glowa;
	}
}

void Lista::wstaw(Student s){
	Wezel* strzalka = glowa;
	
	while(strzalka->getNastepny() != nullptr){
		strzalka = strzalka->getNastepny();
	}
	
	Wezel* nowy = new Wezel(s);
	strzalka->ustawStrzalke(nowy);
}

ostream& operator << (ostream& strumien, const Lista& l){
	Wezel* strzalka = l.glowa;
	
	int i = 1;
	
	while(strzalka != nullptr){
		cout << "Student: " << i << endl;
		cout << strzalka->getStudent() << endl;
		strzalka = strzalka->getNastepny();
		i++;
	}
	return strumien;
}

