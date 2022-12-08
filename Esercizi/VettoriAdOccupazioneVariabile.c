#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAXN 100

int main(void) {

	int seq[MAXN];
	int pos[MAXN];
	int neg[MAXN];
	int N = 0, Np = 0, Nn = 0;
	int i;
	int dato = -1;

	printf("Inserizimi al massimo %d numeri interi\n (0 per terminare)\n", MAXN);

	for (i = 0; i < MAXN && dato != 0; i++) {

		printf("Elemento %d ", i);
		scanf("%d", &dato);
		//seprare le due cose sarebbe stato meglio lettura ed elaborazione
		if (dato != 0) {
			seq[N] = dato;
			N++;

			if (dato > 0) {
				pos[Np] = dato;
				Np++;
			}

			else {
				neg[Nn] = dato;
				Nn++;
			}

		}

		
	}

	//scrittura dei vettori
	printf("\nVettore Positivi\n");
	for (i = 0; i < Np; i++) {
		printf("%d\n", pos[i]);
	}

	printf("\nVettore Negativi\n");
	for (i = 0; i < Nn; i++) {
		printf("%d\n", neg[i]);
	}

	printf("\nPositivi = %d\n", Np);
	printf("Negativi = %d", Nn);


}