#include <stdio.h>
#include <stdlib.h>

typedef struct wezel {
	int dane;
	struct wezel* nastepny;
}wezel;

/*
	1. Dodawanie danych.
	2. Wyświetlanie listy.
*/

void dodaj_dane(wezel** lista);
void dodaj_wezel_do_listy(wezel** lista, wezel* nowe_pudelko);
void wyswietl_liste(wezel* lista);
void uwolnij_pamiec(wezel** lista);

int main(){

	wezel* moja_lista = NULL;
	for(int i = 0; i < 3; i++)
		dodaj_dane(&moja_lista);
	wyswietl_liste(moja_lista);
	uwolnij_pamiec(&moja_lista);

	return 0;
}

void dodaj_dane(wezel** lista){
	printf("Podaj dane: \n");
	int dana;
	scanf("%d",&dana);
	wezel* nowe_pudelko = (wezel*)malloc(sizeof(wezel));
	nowe_pudelko->dane = dana;
	nowe_pudelko->nastepny = NULL;
	dodaj_wezel_do_listy(lista, nowe_pudelko);
}

void dodaj_wezel_do_listy(wezel** lista, wezel* nowe_pudelko){
	//jesli lista jest pusta

	if(*lista == NULL){
		*lista = nowe_pudelko;
	}
	//jesli juz cos w liscie jest
	else{
		//przesuwamy sie za pomoca strzalek po calej liscie az dojdziemy do konca
		for(wezel* licznik = *lista; licznik != NULL; licznik = licznik->nastepny){
			//jesli dotarlismy do konca, to pole nastepny laczymy strzalka z naszym pudelkiem
			if(licznik->nastepny == NULL){
				licznik->nastepny = nowe_pudelko;
				break;
			}
		}
	}
}

void wyswietl_liste(wezel* lista){
	printf("Twoja lista: \n");
	//przejdz przez cala liste i wyswietl dane z kazdego pudelka
	for(wezel* licznik = lista; licznik != NULL; licznik = licznik->nastepny){
		printf("%d \n", licznik->dane);
	}
}

//pamiec zarezerwowana ze sterty musi zostac uwolniona
void uwolnij_pamiec(wezel** lista){
	for(wezel* licznik = *lista; licznik != NULL; licznik = licznik->nastepny){
		free(licznik);
	}
}

