#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int n = -1, somma = 0;

	printf("Inserisci una sequenza di numeri chiusa dallo 0\n");
	while (n != 0) {
		printf("Inserisci un numero: ");
		scanf("%d", &n);
		somma += n; 
	}

	printf("La somma dei numeri nella sequenza e': %d", somma);
}