/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define RAW 5
#define COL 3

int main(void) {

	float mat[RAW][COL];
	int i, j;
	float somma = 0, max_somma = 0;

	printf("Inserisci gli elementi di una matrice %dx%d\n", RAW, COL);
	for (i = 0; i < RAW; i++) {
		for (j = 0; j < COL; j++) {					//con questa disposizione inserisce prima le righe e poi le colonne colonne
			printf("Elemento colonna %d riga %d: ", j, i);
			scanf("%f", &mat[i][j]);
		}
	}

	printf("Matrice Inserita\n");

	for (i = 0; i < RAW; i++) {
		for (j = 0; j < COL; j++) {
			printf("%f	", mat[i][j]); 

		}
		printf("\n");
	}

	for (i = 0; i < COL; i++) {			//inverto sia righe e colonne per operare prima con le colonne sia nella condizione del ciclo che negli indici
		for (j = 0; j < RAW; j++) {
			somma += mat[j][i];
		}

		if (somma > max_somma) {
			max_somma = somma;
		}
		somma = 0;
	}

	printf("La somma piu' grande e' %f: ", max_somma);


}
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define RAW 3
#define COL 3

int main(void) {

	float mat[RAW][COL];
	int i, j;
	float somma = 0, max_somma = 0;

	printf("Inserisci gli elementi di una matrice %dx%d\n", RAW, COL);
	for (i = 0; i < COL; i++) {
		for (j = 0; j < RAW; j++) {			//con questa disposizione inserisce prima le colonne e poi le righe
			printf("Elemento colonna %d riga %d: ", i, j);
			scanf("%f", &mat[j][i]);
		}
	}

	printf("Matrice Inserita\n");

	for (i = 0; i < RAW; i++) {				//OPPURE: facendo inserire prima le colonne dobbiamo invertire durante la visualizzazione in quanto non possiamo 
		for (j = 0; j < COL; j++) {			//stampare prima le colonne per po completarle con le righe
			printf("%f	", mat[i][j]); 

		}
		printf("\n");
	}

	for (i = 0; i < COL; i++) {			
		for (j = 0; j < RAW; j++) {
			somma += mat[j][i];
		}

		if (somma > max_somma) {
			max_somma = somma;
		}
		somma = 0;
	}

	printf("La somma piu' grande e' %f: ", max_somma);


}





