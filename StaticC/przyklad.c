#include <stdio.h>

int a = 2;

static void wypisz_liczbe(){
	int liczba1 = 5;
	printf("%d \n", liczba1);
	liczba1 += a;
}

void wypisz_liczbe2(){
	static int liczba2 = 5;
	printf("%d \n", liczba2);
	liczba2 += a;
}

int main(){

	printf("Wartość a: %d \n", a);
	//printf("Wartość liczba1: %d \n", liczba1);
	//printf("Wartość liczba2: %d \n", liczba2);
	
	for(int i = 0; i < 3; i++)
		wypisz_liczbe();
	
	for(int i = 0; i < 3; i++)
		wypisz_liczbe2();
		
	wypisz_czesc();
	wypisz_hej();
	
	return 0;
}
