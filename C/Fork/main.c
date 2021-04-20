#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <stdlib.h>

#define MAX_SIZE 100
#define DZIECKO "./dziecko"

//znajduje najblizsza potege dwojki
//potrzebne do uzpelnienie lancuchow
//o dlugosciach nie bedacych potega dwojki
int najblizszaPotegaDwojki(int x){
	//zaczynamy od 2^0
	int wynik = 1;
	
	//mnozymy przez 2 (kolejna potega)
	//az bedziemy mieli liczbe wieksza
	//od naszej liczby x
	while(wynik < x)
    	wynik *= 2;
    	
    return wynik;
}

//wyswietlamy slowo na konsole
//id oraz wszystkie argumenty
void wyswietlslowo(int id, int argc, char** argv){
	printf("%d ", id);
    for(int i = 1; i < argc; i++){
    	printf("%s ", argv[i]);
   	}
    printf("\n");
}


int main(int argc, char** argv) {
	
	//sprawdzamy czy podany zostal co najmniej jeden lancuch
	if(argc==1) {
		printf("Podaj co najmniej jeden lancuch znakow! \n");
    	return 0;
    }
    
    //dla kazdego z lancuchow wywolujemy proesy potemne
    for(int a = 1; a < argc; a++){
    	//liczymy dlugosc lancucha
        int dlugosc = strlen(argv[a]);
        //przygotowujemy slowo do przekazania procesom potomnym
		char slowo[MAX_SIZE];

		//sprawdzamy czy dlugosc jest potega dwojki
		if((dlugosc != 0) && ((dlugosc &(dlugosc - 1)) == 0)){
			//przypisujemy znaki z naszego arugmentu do slowa
			for(int i = 0; i < dlugosc; i++)
				slowo[i] = argv[a][i];
			//na koniec puste miejsce
			slowo[dlugosc] = '\0';
		}
		
		else {
			//przypisujemy znaki z naszego arugmentu do slowa
			for(int i = 0; i < dlugosc; i++)
				slowo[i] = argv[a][i];
	
			int potega = najblizszaPotegaDwojki(dlugosc);
			
			//uzupelniamy brakujace miejsca literami x
			//az dlugosc slowa rowna bedzie potedze dwojki
			for(int i = dlugosc; i < potega; i++)
				slowo[i] = 'X';
				
			//na koniec puste miejsce	
			slowo[potega] = '\0';
		}
		
   		//id, liczby sluzace do identyfikacji procesow
	    pid_t pid_dziecka, wpid;
	    
	    //zmienna pomocnicza, wait potrzebuje wskaznika na liczbe jako arguemntu
		int status = 0;
    
    	if ((pid_dziecka = fork()) == 0) {
			for (int i = 0; i < 2; i++) {
   				execv("./dziecko", (char *[]){"./dziecko", slowo, NULL});
        		exit(0);
   			}
		}

		//ojciec czeka na dzieci aż zakończą wykonywanie
		//wait zwraca jakas liczby, jesli udalo sie przypisac
		//to znaczy ze proces dziecka zostal zakonczony
		while ((wpid = wait(&status)) > 0); 
		
  	}

  	wyswietlslowo(getpid(), argc, argv);
  
    return 0; 
} 
