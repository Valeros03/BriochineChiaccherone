/* Leggere da tastiera una sequenza di lunghezza ignota a priori di numeri interi positivi o nulli.
A partire dal secondo numero introdotto, visualizzare ogni volta la media di tutti i numeri introdotti fino a quel momento.
La sequenza dei numeri in input termina quando viene introdotto un valore negativo.
Il valore negativo non fa parte della sequenza */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void) {

	int n = 0, c = 1, somma = 0;
	float media = 0;
	
	printf("Questo programma calcola la media in tempo reale di una sequenza di numeri inserita da input"
	   "\n\nInserisci un numero maggiore o uguale a zero(minore di zero per uscire): ");

	scanf("%d", &n);
	somma = n;    //somma = n in quanto n è il primo numero della sequenza

	while (n >= 0) {

		printf("Inserisci un numero maggiore o uguale a zero(minore di zero per uscire): ");
		scanf("%d", &n);

		
		if (n >= 0) {	//perchè devo considerare solo i maggiori o nulli nel calcolo della media / nella sequenza
			c++;
			somma += n;
			media = (float)somma / c;
		}
		
		printf("Media: %.2f \n", media);
		
	}

	printf("Fine esecuzione!");
	
}