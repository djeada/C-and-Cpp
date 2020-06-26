#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <stdlib.h>

#define MAX_SIZE 100

//wyswietlamy slowo na konsole
//id oraz wszystkie argumenty
void wyswietlInfo(int id, int argc, char** argv){
	printf("%d ", id);
    for(int i = 1; i < argc; i++){
    	printf("%s ", argv[i]);
   	}
    printf("\n");
}

int main(int argc, char** argv) {
    
    char info [MAX_SIZE];
    strcpy(info, "");
    
    for(int i = 1; i < argc; i++){
		strcat(info, argv[i]);
		strcat(info, " ");
   	}
    
	//tablica lancuchow trzya dwa napisy, lewa i prawa czesc slowa
    char slowa[2][MAX_SIZE] = {"",""};
    
    //wyciagamy slowo z argumentow przekazanych programowi
    char* slowo = argv[argc-1];
    
    //liczymy dlugosc slowa
    int dlugosc = strlen(slowo);
    	
   	//id, liczby sluzace do identyfikacji procesow
	pid_t pid_dziecka, wpid;
	
	//zmienna pomocnicza, wait potrzebuje wskaznika na liczbe jako arguemntu
	int status = 0;
    
    //jesli slowo jest krotsze niz 2 nie kontynujemy procesu
    if(dlugosc > 1){
    
    	//znajdujemy srodek
    	int srodek = dlugosc/2;

		//czesc slowa do srodka przekazujemy do
		//tablicy slowa na pozycje 0
		for(int i = 0; i < srodek; i++) {
				slowa[0][i]= slowo[i];
		}
    	
    	//na koniec puste miejsce	
		slowa[0][srodek] = '\0';
		
		//czesc slowa od srodka przekazujemy do
		//tablicy slowa na pozycje 1
		for(int i = 0; i <= srodek; i++) {
			slowa[1][i]= slowo[srodek + i];
		}
			
		//na koniec puste miejsce	
		slowa[1][srodek+1] = '\0';
		
		//tworzymy dwa procesy potemne
		//jednemu dajemy lewa czesc slowa
		//drugiemu prawa czesc
		for (int i = 0; i < 2; i++) {
    		if ((pid_dziecka = fork()) == 0) {
   				execv(argv[0], (char *[]){argv[0], info, slowa[i], NULL});
        		exit(0);
   			}
		}

		//ojciec czeka na dzieci aż zakończą wykonywanie
		//wait zwraca jakas liczby, jesli udalo sie przypisac
		//to znaczy ze proces dziecka zostal zakonczony
		while ((wpid = wait(&status)) > 0); 
		
	}

	wyswietlInfo(getpid(), argc, argv);
  
    return 0; 
} 
