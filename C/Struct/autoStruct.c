/* 
Giacomo Redi 5F 8/10/2025
Esercizio - Strutture
Scrivere un programma in C che dopo aver dichiarato una struttura denominata Auto con i seguenti
campi: ModelloAuto, marca, cilindrata, prezzo, anno_immatricolazione, targa; determini:
1) Il prezzo + alto e quello + basso visualizzando anche il modello dell'auto;
2) Ordinare la lista delle auto in base all'anno d'immatricolazione;
3) Visualizzare il nome delle auto a partire da un prezzo scelto dall'utente.
4) Ricerchi un Auto scelta dall’utente (utilizzare il campo targa): visualizzando tutti i campi;
5) La media dei prezzi delle auto inserite;
6) Visualizzare le Auto con anno di immatricolazione scelto dall’utente;
*/

#include <stdio.h>
#include <string.h>

struct Auto {
    char modelloAuto[50];
    char marca[50];
    int cilindrata;
    double prezzo;
    int annoImmatricolazione;
    char targa[8];
};

void inserimentoAuto(struct Auto a[], int nAuto) {
    for (int i = 0; i < nAuto; i++) {
        printf("Inserimento Auto %d\n", i + 1);
        printf("Modello: ");
        scanf("%s", a[i].modelloAuto);
        printf("\n Marca: ");
        scanf("%s", a[i].marca);
        printf("\n Cilindrata: ");
        scanf("%d", &a[i].cilindrata);
        printf("\n Prezzo: ");
        scanf("%lf", &a[i].prezzo);
        printf("\n Anno immatricolazione: ");
        scanf("%d", &a[i].annoImmatricolazione);
        printf("\n Targa: ");
        scanf("%s", a[i].targa);
    }
}

int prezzoPiuAlto(struct Auto a[], int nAuto) {
    int indice = 0;
    for (int i = 1; i < nAuto; i++) {
        if (a[i].prezzo > a[indice].prezzo) {
            indice = i;
        }
    }
    return indice;
}

int prezzoPiuBasso(struct Auto a[], int nAuto) {
    int indice = 0;
    for (int i = 1; i < nAuto; i++) {
        if (a[i].prezzo < a[indice].prezzo) {
            indice = i;
        }
    }
    return indice;
}

void visualizza(struct Auto a[], int nAuto) {
    for (int i = 0; i < nAuto; i++) {
        printf("Macchina numero: %d\n", i + 1);
        printf("Modello auto: %s\n", a[i].modelloAuto);
        printf("Marca: %s\n", a[i].marca);
        printf("Cilindrata: %d\n", a[i].cilindrata);
        printf("Prezzo: %.2lf\n", a[i].prezzo);
        printf("Anno di immatricolazione: %d\n", a[i].annoImmatricolazione);
        printf("Targa: %s\n", a[i].targa);
    }
}

void visualizzaAPartireDaUnPrezzo(struct Auto a[], int nAuto, double prezzo) {
    for (int i = 0; i < nAuto; i++) {
        if (a[i].prezzo >= prezzo) {
            printf("Modello: %s", a[i].modelloAuto);
        }
    }
}

int cercaAuto(struct Auto a[], int nAuto, char targa[]) {
    for (int i = 0; i < nAuto; i++) {
        if (strcmp(a[i].targa, targa) == 0) {
            return i;
        }
    }
    return -1;
}

double mediaPrezzi(struct Auto a[], int nAuto) {
    double somma = 0;
    for (int i = 0; i < nAuto; i++) {
        somma += a[i].prezzo;
    }
    return somma / nAuto;
}

void visualizzaInBaseAnno(struct Auto a[], int nAuto, int annoImmatricolazione) {
    printf("Auto immatricolate nel %d:\n", annoImmatricolazione);
    for (int i = 0; i < nAuto; i++) {
        if (a[i].annoImmatricolazione == annoImmatricolazione) {
            printf("Modello Auto: %s Marca: %s, Prezzo: %.2lf, Targa: %s\n", a[i].modelloAuto, a[i].marca, a[i].prezzo, a[i].targa);
        }
    }
}

void ordinaPerAnno(struct Auto a[], int nAuto) {
    struct Auto temp;
    for (int i = 0; i < nAuto - 1; i++) {
        for (int j = i + 1; j < nAuto; j++) {
            if (a[i].annoImmatricolazione > a[j].annoImmatricolazione) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main() {
    int nAuto = 0;
    int esci = 1;
    struct Auto collezioneAuto[100];

    do {
        int scelta;
        printf("---------- MENU ----------\n");
        printf("1. Inserimento\n");
        printf("2. Visualizza\n");
        printf("3. Prezzo più alto e più basso\n");
        printf("4. Ordina lista per anno immatricolazione\n");
        printf("5. Visualizza auto a partire da un prezzo\n");
        printf("6. Cerca un'auto (per targa)\n");
        printf("7. Media dei prezzi\n");
        printf("8. Visualizza auto per anno immatricolazione\n");
        printf("9. Esci\n");

        printf("Scelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
                printf("Quante auto vuoi inserire? ");
                scanf("%d", &nAuto);
                inserimentoAuto(collezioneAuto, nAuto);
                break;

            case 2:
                visualizza(collezioneAuto, nAuto);
                break;

            case 3: {
                int max = prezzoPiuAlto(collezioneAuto, nAuto);
                int min = prezzoPiuBasso(collezioneAuto, nAuto);
                printf("\nAuto con prezzo più alto: %s %.2lf euro\n", collezioneAuto[max].modelloAuto, collezioneAuto[max].prezzo);
                printf("Auto con prezzo più basso: %s %.2lf euro\n", collezioneAuto[min].modelloAuto, collezioneAuto[min].prezzo);
                break;
            }

            case 4:
                printf("Auto ordinate in base all'anno");
                ordinaPerAnno(collezioneAuto, nAuto);
                break;

            case 5: {
                double prezzo;
                printf("Inserisci un prezzo da cui visualizzare le auto: ");
                scanf("%lf", &prezzo);
                visualizzaAPartireDaUnPrezzo(collezioneAuto, nAuto, prezzo);
                break;
            }

            case 6: {
                char targaDaCercare[8];
                printf("Inserisci la targa del veicolo da cercare: ");
                scanf("%s", targaDaCercare);
                int pos = cercaAuto(collezioneAuto, nAuto, targaDaCercare);
                if (pos != -1) {
                    printf("\n Veicolo trovato:\n");
                    printf("Modello: %s \n Marca: %s\n Cilindrata: %d\n Prezzo: %.2lf\n Anno: %d\n Targa: %s\n",
                           collezioneAuto[pos].modelloAuto, collezioneAuto[pos].marca,
                           collezioneAuto[pos].cilindrata, collezioneAuto[pos].prezzo,
                           collezioneAuto[pos].annoImmatricolazione, collezioneAuto[pos].targa);
                } else {
                    printf("Auto non trovata.\n");
                }
                break;
            }

            case 7:
                printf("\nLa media dei prezzi è: %.2lf\n", mediaPrezzi(collezioneAuto, nAuto));
                break;

            case 8: {
                int anno;
                printf("Inserisci l'anno di immatricolazione: ");
                scanf("%d", &anno);
                visualizzaInBaseAnno(collezioneAuto, nAuto, anno);
                break;
            }

            case 9:
                printf("Uscita dal programma...\n");
                esci = 0;
                break;
        }

    } while (esci == 1);

    return 0;
}
