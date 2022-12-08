/*Array multidimensionali*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#define RIG 2
#define COL 3 //definisco riga e colonna come nell'array all'inizio del programma come costanti
#define DIM 5
int main() {

	int mat[COL][RIG] = { {3,2}, {0,0},{2,3} }; //dichiarazione di una matrice
	for (int i = 0; i < COL; i++) {
		for (int j = 0; j < RIG; j++) {
			printf("%6d", mat[i][j]); //il 6 serve per lasciare lo spazio di dimensione di un numero a sei cifre
		}
		printf("\n");
	}

	char s[DIM] = { 'c','i','a','o','\0' }; //string in c
	char s1[DIM] = "ciao";					//posso inserire sempre Dim -1 caratteri, posos anche omettere la dimensione perch� gli viene attribuita con l'assegnazione
								/*La stringa in c � sempre terminata dallo \0 carattere terminatore
								all'interno di un vettore di caratteri posso lavorare con strighe pi� piccole della dimensione del vettore */

	//per stampare...
	printf("%s", s);

	//per inserire...
	scanf("%s", s1); //tuttavia si ferma allo spazio
	//per leggere la stringa con gli spazi senza andare a capo
	scanf("%[^\n]s", s);
	//purtroppo la scanf legge pi� caratteri di quanto il vettore � lungo, ci� comporta che non sa dove mettere il carattere terminatore \0
	printf("La lunghezza della stringa �: %d ", strlen(s));

	// s = s1; non pu� esistere...<string.h> � una libreria del c che ha diverse funzioni utili per laovrare con le stringhe
	//alcune funzioni di questa libreria
	strcpy(s, s1); //copia la stringa s nella s1
	strlen(s1); //restituisce la lunghezza della stringa
	strcmp(s, s1); //
	strcat(s, s1); //mette la stringa s alla fine della stringa s1







}