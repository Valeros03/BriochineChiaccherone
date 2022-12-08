#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void conversioneBinaria(float a);

int main(void) {


	int anno = 0;
	int numeroMatricola = 0;
	int giorno = 1;
	printf("Inserisci l'anno di nascita\n");
	scanf("%d", &anno);
	printf("Inserisci le ultime due cifre del numero di matricola\n");
	scanf("%d", &numeroMatricola);
	printf("Inserisci il tuo giorno di nascita\n");
	scanf("%d", &giorno);
	
	float decimale = (float)anno * numeroMatricola / giorno;
	conversioneBinaria(decimale);


}


void conversioneBinaria(float a) {

	int parteIntera = a;
	int f = 0;
	int v[200];
	

	float parteDecimale = (float)(a - parteIntera);
	printf("Ecco il numero in binario\n");
	
	int contatore = 0;

	while (parteIntera != 0) {
		if (parteIntera%2 == 1) {
			v[f] = 1;
		}
		else {
			v[f] = 0;
		}
		f++;
		parteIntera = parteIntera / 2;
	}
	f = 199;
	while (f >= 0) {
		if (v[f] == 0 || v[f] == 1) {
			printf("%d", v[f]);
			
		}
		
		f--;
	}

	printf(".");
	
	while (parteDecimale != 1.0f && contatore != 4) {
		if (parteDecimale * 2 >= 1) {
			printf("%d", 1);
		}
		else {
			printf("%d", 0);
		}
		parteDecimale *= 2.0f;
		if (parteDecimale > 1) {
			parteDecimale -= 1;
		}
		
		contatore++;
	}

}