#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {

	int n = 0, u = 0, somma = 0;
	printf("Inserisci il numero di elementi di cui vuoi fare la somma: ");
	scanf("%d", &n);

	while (n != 0) {
		printf("Inserisci un numero: ");
		scanf("%d", &u);
		somma += u;
		n--;
	}
	printf("La somma dei numeri inseriti e' : %d ", somma);
	
}