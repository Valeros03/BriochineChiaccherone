#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 20

typedef struct {

    char nome[31];
    float temp;

}citta;

int main() {

    citta vet_cit[MAX];
    int dim = 0;
    citta ord;
    float somma = 0, max_temp, min_temp;


    do {

        printf("Inserisci il numero di citta (max %d)", 20);
        scanf("%d", &dim);

    } while (dim < 0 || dim > 20);
    
    for (int i = 0; i < dim; i++) {

        printf("Inserisci il nome della citta %d: ", i);
        scanf("%s", vet_cit[i].nome);
        printf("Inserisci la temperatura della citta %d: ", i);
        scanf("%f", &vet_cit[i].temp);

    }

    /*
                Bubble sort
    for (int j = 0; j < dim-1; j++)
        for (int i = 0; i < dim-1; i++) {
            if (vet_cit[i].temp > vet_cit[i+1].temp) {
                ord = vet_cit[i+1];
                vet_cit[i + 1] = vet_cit[i];
                vet_cit[i] = ord;
            }
        }
         printf("la citta' con la temperatura minima e': %s con una temperatura di: %f\n",vet_cit[0].nome,vet_cit[0].temp);
         printf("la citta' con la temperatura Massima e': %s con una temperatura di: %f\n", vet_cit[dim-1].nome, vet_cit[dim-1].temp);
    */


    //con ricerca del massimo o minimo
    citta max = vet_cit[0], min = vet_cit[0];
    for (int i = 1; i < dim; i++) {

        if (max.temp < vet_cit[i].temp) {
            max = vet_cit[i];
        }

    }
    for (int i = 1; i < dim; i++) {

        if (min.temp > vet_cit[i].temp) {
            min = vet_cit[i];
        }

    }

    printf("la citta' con la temperatura minima e': %s con una temperatura di: %f\n", min.nome, min.temp);
    printf("la citta' con la temperatura Massima e': %s con una temperatura di: %f\n", max.nome, max.temp);

    //calcolo somma per fare la media
    for (int i = 0; i < dim; i++) {
    
        somma += vet_cit[i].temp;
    
    }

    //stampa citta con temperatura superiore alla media
    printf("        Citta' con temperatura superiore alla media: \n");
    for (int i = 0; i < dim; i++) {

        if (vet_cit[i].temp > somma / 2) {
            printf("%s    %f", vet_cit[i].nome, vet_cit[i].temp);
        }

    }
    

}
