#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef enum {

	true = 0, false

}bool;

typedef struct Data {

	int giorno;
	char mese[20];
	int anno;

}Data;

typedef struct{		//si possono definire nuovi tipi utilizzando la keyword typedef e mettere il nome della struct dopo l'implementazione della struct (quest'ultimo è facoltativo)

	char nome[20];
	int anni;
	Data DataDiNasc;		//*
	bool sex;

}Persona;
/* Possono essere di tipo struct o ridefinire nuovi tipi, ciò permette di lavorare di lavorare con un livello di astrazione 
più alto vicino alla logica comune */


int main(void) {

	Persona p1, p2;  //possiamo anche omettere la parola struct a ogni dichiarazione*
	p1 = p2;
	bool a = 1; //possiamo dare anche in questo modo i valori della enum ma risulta essere più confusionario e non vi è un controllo sul fatto
				//che a destra potremmo avere un numero non presente nell'enum


}

