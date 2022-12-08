/*una collezione finita di variabili non necessariamente dello stesso tipo*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Data {
	
	int giorno;
	char mese[20];
	int anno;

};

struct Persona {

	char nome[30];
	int eta;
	struct Data DataDiNasc;
	float stipendio; 

}Bob, Antonio; //possono essere annidate



int main(void) {

	struct Persona p1, p2;
	struct Persona elenco[50];
	p2.eta = 20;

	p1 = p2; //è possibile l'assegnazione tra due variabili di tipo struttura ma non il confronto (p1==p2);
}