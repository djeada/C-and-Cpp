#include "stos.h"

Stos::Stos(){
	rozmiar = 3;
	indeks_wierzcholka = -1;
	tablica = new int [rozmiar];
}


Stos::Stos(int r) {
	rozmiar = r;
	indeks_wierzcholka = -1;
	tablica = new int [rozmiar];
}

Stos::Stos(const Stos& inny_stos){
	rozmiar = inny_stos.rozmiar;
	indeks_wierzcholka = inny_stos.indeks_wierzcholka;
	tablica = new int [inny_stos.rozmiar];
	for (int i = 0; i <= indeks_wierzcholka; i++)
		tablica[i] = inny_stos.tablica[i];
}

Stos::~Stos() {
	delete [] tablica;
}


bool Stos::czyPusty() {
	if (indeks_wierzcholka < 0) 
		return true;
	return false;
}

bool Stos::czyPelny() {
	if (indeks_wierzcholka >= rozmiar - 1) 
		return true;
	return false;
}

int Stos::zdejmij() {
	if (czyPusty()) {
    	cerr <<  "Stos jest pusty!" << endl;
		exit(EXIT_FAILURE);
	}
	indeks_wierzcholka--;
	return tablica[indeks_wierzcholka + 1];
}

void Stos::odloz(int x) {
	if (czyPelny()) {
    	cerr << "Stos jest pelny!" << endl;
		exit(EXIT_FAILURE);
	}
	indeks_wierzcholka++;
	tablica[indeks_wierzcholka] = x;
}

ostream& operator << (ostream& out, Stos &s){
	cout << "Twoj piekny stos: " << endl;
	for (int i = 0; i <= s.indeks_wierzcholka; i++)
		cout << s.tablica[i] << " ";
	return out;
}

Stos operator ++ (Stos &s) {
	int *tmp = new int[s.rozmiar + 1];
	
	for (int i = 0; i <= s.indeks_wierzcholka; i++)
		tmp[i] = s.tablica[i];
		
	delete[] s.tablica;
	s.tablica = tmp;
	
	s.rozmiar++;
	
	return s;
}

Stos operator -- (Stos &s) {
	int *tmp = new int[s.rozmiar - 1];
	s.rozmiar--;
	
	if(s.rozmiar == s.indeks_wierzcholka){
		s.indeks_wierzcholka--;
	}
		
	for (int i = 0; i <= s.indeks_wierzcholka; i++)
		tmp[i] = s.tablica[i];
		
	delete[] s.tablica;
	s.tablica = tmp;
	
	return s;
}


