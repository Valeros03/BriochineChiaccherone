#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 10

int main(void) {

	int vet[N];
	int i, dato, trovato = 0, pos =-1;

	for (i = 0; i < N; i++) {
		printf("Elemento %d: ", i);
		scanf("%d", &vet[i]);
	}

	printf("Elemento da cercare: ");
	scanf("%d", &dato);

	for (i = 0; i < N; i++) {

		if (vet[i] == dato) {
			trovato = 1;
			pos = i;
			printf("\nElemento %d trovato in posizione %d", dato, pos);
		}

	}

	if (!trovato) {
		printf("\nElemento non trovato\n");
	}
	

}