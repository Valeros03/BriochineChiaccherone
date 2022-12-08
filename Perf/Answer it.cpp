#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <ctime>
#include <unistd.h>
#include <thread>
#include <windows.h>
#include <utility>
#define CTR_SECURE_NO_DEPRECATE
#define N 2


using namespace std;



int domandaUno();
int controlloPunti();
int poszioneRandomRisposta();
int generatoreDomandeRandom();
void numeroDomandine();
void regoleDiGioco();
void numeroPlayer();
int leggiIntero(string msg);

int numeroGiocatori;
int numeroDomande;
int unicita[201];
char matDomande[200][200];
char matRisposte[200][100];
char posizioneCorretta[4][100];
char distrattoreUno[200][100];
char distrattoreDue[200][100];
char distrattoreTre[200][100];
char distrattoreQuattro[200][100];


typedef struct giocatore {

	char nome[40];
	int punteggio;


}giocatore;
giocatore giocatori[20];


void caricaDomande() {
	FILE* file;
	FILE* fileDue;
	FILE* fileDistrattoreUno;
	FILE* fileDistrattoreDue;
	FILE* fileDistrattoreTre;
	FILE* fileDistrattoreQuattro;

	file=fopen("Data\\dcvc.txt", "r");
	for (int i = 0; i < 200; i++) {

		fgets(matDomande[i], 200, file);
		for (int q = 0; q < 200; q++) {

			if ((matDomande[i][q] > 65 && matDomande[i][q] < 92) || (matDomande[i][q] > 97 && matDomande[i][q] < 124) || matDomande[i][q] == 64 || matDomande[i][q] == 97 || matDomande[i][q] == 33 || (matDomande[i][q] > 48 && matDomande[i][q] < 59) || (matDomande[i][q] > 130 & matDomande[i][q] < 152)) {

				matDomande[i][q] = matDomande[i][q] - 1;
				
			}
		}
	}

	fileDue=fopen( "Data\\cbin.txt", "r");
	for (int i = 0; i < 200; i++) {
		fgets(matRisposte[i], 100, fileDue);
		for (int q = 0; q < 100; q++) {
			if (matRisposte[i][q] > 65 && matRisposte[i][q] < 92 || matRisposte[i][q]>97 && matRisposte[i][q] < 124 || matRisposte[i][q] == 64 || matRisposte[i][q] == 97 || matRisposte[i][q] == 33 || matRisposte[i][q]>48 && matRisposte[i][q] < 59) {

				matRisposte[i][q] = matRisposte[i][q] - 1;

			}
		}

	}
	fileDistrattoreUno=fopen("Data\\Ansvin.txt", "r");
	for (int i = 0; i < 200; i++) {
		fgets(distrattoreUno[i], 100, fileDistrattoreUno);
		for (int q = 0; q < 100; q++) {
			if (distrattoreUno[i][q] > 65 && distrattoreUno[i][q] < 92 || distrattoreUno[i][q]>97 && distrattoreUno[i][q] < 124 || distrattoreUno[i][q] == 64 || distrattoreUno[i][q] == 97 || distrattoreUno[i][q] == 33 || distrattoreUno[i][q]>48 && distrattoreUno[i][q] < 59) {

				distrattoreUno[i][q] =distrattoreUno[i][q] - 1;

			}
		}
		
	}
	fileDistrattoreDue=fopen("Data\\Bnsvin.txt", "r");
	for (int i = 0; i < 200; i++) {
		fgets(distrattoreDue[i], 100, fileDistrattoreDue);
		for (int q = 0; q < 100; q++) {
			if (distrattoreDue[i][q] > 65 && distrattoreDue[i][q] < 92 || distrattoreDue[i][q]>97 && distrattoreDue[i][q] < 124 || distrattoreDue[i][q] == 64 || distrattoreDue[i][q] == 97 ||distrattoreDue[i][q] == 33 || distrattoreDue[i][q]>48 && distrattoreDue[i][q] < 59) {

				distrattoreDue[i][q] =distrattoreDue[i][q] - 1;

			}
		}
		
	}
	fileDistrattoreTre=fopen("Data\\qnsvin.txt", "r");
	for (int i = 0; i < 200; i++) {
		fgets(distrattoreTre[i], 100, fileDistrattoreTre);
		for (int q = 0; q < 100; q++) {
			if (distrattoreTre[i][q] > 65 && distrattoreTre[i][q] < 92 || distrattoreTre[i][q]>97 && distrattoreTre[i][q] < 124 || distrattoreTre[i][q] == 64 || distrattoreTre[i][q] == 97 ||distrattoreTre[i][q] == 33 || distrattoreTre[i][q]>48 && distrattoreTre[i][q] < 59) {

				distrattoreTre[i][q] =distrattoreTre[i][q] - 1;
            }
			}
	}
	fileDistrattoreQuattro=fopen("Data\\wnsvin.txt", "r");
	for (int i = 0; i < 200; i++) {
		fgets(distrattoreQuattro[i], 100, fileDistrattoreQuattro);
			for (int q = 0; q < 100; q++) {
			if (distrattoreQuattro[i][q] > 65 && distrattoreQuattro[i][q] < 92 || distrattoreQuattro[i][q]>97 && distrattoreQuattro[i][q] < 124 || distrattoreQuattro[i][q] == 64 || distrattoreQuattro[i][q] == 97 ||distrattoreQuattro[i][q] == 33 || distrattoreQuattro[i][q]>48 && distrattoreQuattro[i][q] < 59) {

				distrattoreQuattro[i][q] =distrattoreQuattro[i][q] - 1;
            }
			}
	}

}

void memorizzaGiocatori() {

	for (int i = 0; i < numeroGiocatori; i++) {
		cout << "inserisci il nome del giocatore " << i + 1 << endl;
		cin >> giocatori[i].nome;
}
}

void turnoGiocatore() {

	int b;
	int i;
    
		for (i = 0; i < numeroGiocatori; i++) {
			cout << endl;
			cout << " \t tocca al giocatore " << i + 1 << " " << giocatori[i].nome << endl;
			b=domandaUno();
			if (b == 0) {
				giocatori[i].punteggio++;
			}
		}
}

int domandaUno() {
    
	int risposta;
	string corretta = " Risposta esatta! ";
	string sbagliata = " Risposta sbagliata :( ";
	int u = poszioneRandomRisposta();
	int j = generatoreDomandeRandom();
	if (j < 51) {
		cout << "STORIA E GEOGRAFIA:" << endl;
		cout << matDomande[j] << endl << endl;
	}
	if (j < 101 && j>50) {
		cout << "ARTE:" << endl;
		cout << matDomande[j] << endl << endl;
	}if (j < 151 && j>100) {
		cout << "SPORT:" << endl;
		cout << matDomande[j] << endl << endl;
	}if (j > 151) {
		cout << "SCIENZE:" << endl;
		cout << matDomande[j] << endl << endl;
	}
	memcpy(posizioneCorretta[0], distrattoreUno[j], sizeof(posizioneCorretta[u]));
	memcpy(posizioneCorretta[1], distrattoreDue[j], sizeof(posizioneCorretta[u]));
	memcpy(posizioneCorretta[2], distrattoreTre[j], sizeof(posizioneCorretta[u]));
	memcpy(posizioneCorretta[3], distrattoreQuattro[j], sizeof(posizioneCorretta[u]));
	memcpy(posizioneCorretta[u], matRisposte[j], sizeof(posizioneCorretta[u]));


	for (int i = 0; i < 4; i++) {
		cout << i + 1 << ")" << posizioneCorretta[i] << endl;
	}
    
	risposta = leggiIntero("\n");
	system("cls");
	if (risposta == u + 1) {
		cout << "*********************\n*"<<corretta<<" *\n*********************" << endl;
		sndPlaySound("Data\\Sound\\correct.wav",SND_SYNC);
		return 0;
	}
	if(risposta!= u+1){
		cout << "*************************\n*"<<sbagliata<<" *\n*************************" << endl;
		cout<<"era la "<< u+1<<") "<< matRisposte[j]<<endl;
		sndPlaySound("Data\\Sound\\wrong.wav",SND_SYNC);
		return 1;
	}
}

void visualizzaPunteggio() {
	
	for (int i = 0; i < numeroGiocatori; i++) {
		cout << giocatori[i].nome << " ha fatto " << giocatori[i].punteggio << " punti" << endl;
		if(giocatori[i].punteggio==0){
			sndPlaySound("Data\\Sound\\bad.wav", SND_SYNC);
		}else{
	    sndPlaySound("Data\\Sound\\Applausi.wav", SND_SYNC);
	}
	}
	sndPlaySound("Data\\Sound\\musa1", SND_ASYNC|SND_LOOP);
}


int main() {
    system("color 70");
	string s1, s2, s3;
	cout << "   \t                             BENVENUTOOOO!!   " << endl;
	caricaDomande();
	regoleDiGioco();
	sndPlaySound("Data\\Sound\\musa1", SND_ASYNC|SND_LOOP);

nuovissimaPartita:
	for (int i = 0; i < 201; i++){
		unicita[i] = 0;
	}
	numeroPlayer();
	memorizzaGiocatori();
     int numeroTurno=1;
nuovaPartita:
	
	numeroDomandine();
	cout << "Pronti per iniziare?" << endl;
	system("pause");
	sndPlaySound("Data\\Sound\\reset.wav",SND_ASYNC);
	system("cls");
	for (int j = 0; j < numeroDomande; j++) {
	cout<<"***************************\n*    Siamo al Turno "<<numeroTurno<<"     *\n***************************"<<endl;
	turnoGiocatore();
	numeroTurno++;
}
	visualizzaPunteggio();

fineGioco:

	cout << "Volete altre domande?" << endl;
	cin >> s1;
	if (s1 == "si" || s1 == "Si" || s1 == "yes" || s1 == "Yes" || s1 == "sI" || s1 == "yep" || s1 == "Yep") {
		goto nuovaPartita;
	}
	else {
		cout << "Vuoi iniziare una nuova partita?" << endl;
		cin >> s2;
		if (s2 == "si" || s2 == "Si" || s2 == "yes" || s2 == "Yes" || s2 == "sI" || s2 == "yep" || s2 == "Yep") {
			for (int i = 0; i < numeroGiocatori; i++) {
				giocatori[i].punteggio = 0;
			}
			goto nuovissimaPartita;
		}
		else {
			cout << "Vuoi chiudere il gioco?" << endl;
			cin >> s3;
			if (s3 == "si" || s3 == "Si" || s3 == "yes" || s3 == "Yes" || s3 == "sI" || s3 == "yep" || s3 == "Yep") {

			}
			else {
				goto fineGioco;
			}
		}
	}

}
int generatoreDomandeRandom() {
	srand(time(0));
	int r;
	do {
		r = rand() % 200 ;
	} while (unicita[r] != 0);
	unicita[r] = 1;
	return r;
}
int poszioneRandomRisposta() {
	srand(time(0));
	int t = rand() % 4;
	return t;
}

void regoleDiGioco() {
	char regoleBuffer[7][2000];
	FILE* file;
	file=fopen("Data\\Regole.txt", "r");
	for (int i = 0; i < 7; i++) {
		fgets(regoleBuffer[i], 200, file);
		cout << regoleBuffer[i] << endl;
	}
	cout<<endl;
}
void numeroPlayer() {

	numeroGiocatori = leggiIntero("Quanti giocatori siete?");
}
void numeroDomandine() {

	numeroDomande = leggiIntero("A quante domande a testa volete rispondere(MAX 200)?");

}
int leggiIntero(string msg) {
	int d;

	while (true) {
		cout << msg << endl;;
	
		cin >> d;
		if (cin.fail()) {
			cout << "non ho capito, puoi ripetere?" << endl;
			cin.clear();
			cin.ignore(100, '\n');
			continue;
		}
		cin.ignore(1000, '\n');
		if (cin.gcount() > 1) {
			cout << "non ho capito, puoi ripetere?" << endl;
			continue;

		}
		break;
	}
	return d;
}
