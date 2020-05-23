#include <iostream>
#include "Lista.h"
#include "Student.h"

using namespace std;

int main() {

	Student s1("adam", 1);
	
	
	Student s2;
	
	Lista nasza_lista(s1);
	nasza_lista.wstaw(s2);
	nasza_lista.wstaw(s2);
	
	cout << nasza_lista;

	return 0;
}


