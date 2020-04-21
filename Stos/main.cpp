#include <iostream>
#include "stos.h"

using namespace std;

int main(){

	Stos s1;
	
	s1.odloz(5);
	s1.odloz(3);
	s1.odloz(2);
	cout << boolalpha << s1.czyPelny() << endl;
	++s1;
	s1.odloz(2);
	++s1;
	s1.odloz(2);
	
	cout << s1 << endl;
	
	s1.zdejmij();
	s1.zdejmij();
	s1.zdejmij();
	s1.zdejmij();
	
	cout << s1 << endl;
		
	return 0;
}
