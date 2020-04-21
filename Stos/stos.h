#ifndef stos_h
#define stos_h

#include <iostream>

using namespace std;

class Stos {
	private:
		int* tablica;
		int rozmiar;
		int indeks_wierzcholka;	
	public:
		Stos();
		Stos(int r);
		Stos(const Stos& inny_stos);
		~Stos();
		
		void odloz(int x);
		int zdejmij();
		bool czyPusty();
		bool czyPelny();
		
		friend Stos operator ++ (Stos &s);
		friend Stos operator -- (Stos &s);
		
		friend ostream& operator << (ostream& out, Stos &s);
};

#endif

