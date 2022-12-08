#define _CRT_SECURE_NO_WARNINGS
#define N 20
#include <stdio.h>



int main() {

	int n = 0, a = 0, c_max = 0, a_max = 0, l = 0, c = 0;
	char* bob;
	scanf("%s", bob);
	printf("%s", bob);

	do {

		printf("Inserisci la lunghezza della sequenza: ");
		scanf("%d", &l);

	} while (l < 0);

	while (l != 0) {

		printf("Inserisci un numero ");
		scanf("%d", &n);
		if (n != a) {  //nuova sequenza
			a = n;
			c = 0;
		}
		c++;

		if (c > c_max) {  //stabilisce la nuova sequenza più lunga 
			c_max = c;
			a_max = a;
		}
		
		l--;
	}

	printf("Valore ripetuto: %d\n", a_max);
	printf("Volte ripetuto: %d", c_max);

}