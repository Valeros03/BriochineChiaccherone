#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 5

struct studente {

	char cognome[31];
	char nome[21];
	int voto;

};

int main(void) {

	struct studente v[N];
	for (int i = 0; i < N; i++) {
		printf("		*Studente %d*	\n", i);
		printf("Inserisci il cognome: ");
		scanf("%s", v[i].cognome);
		printf("Inserisci il nome: ");
		scanf("%s", v[i].nome);
		printf("Inserisci il voto: ");
		scanf("%d", &v[i].voto);

	}
	//punto 1
	for (int i = 0; i < N; i++) {

		printf("%s	%s\n", v[i].cognome, v[i].nome);

	}

	//punto 2
	int somma = 0;
	for (int i = 0; i < N; i++) {
		somma += v[i].voto;
	}
	float media = (float)somma / N;
	printf("Media: %.2f", media);

	//punto 3
	for (int i = 0; i < N; i++) {
		if (v[i].voto < 27) {
			printf("%s		%s\n", v[i].nome, v[i].cognome);
		}
	}
}