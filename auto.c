/*Esercizio - Strutture
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

struct Auto{
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
        printf("Marca: ");
        scanf("%s", a[i].marca);
        printf("Cilindrata: ");
        scanf("%d", &a[i].cilindrata);
        printf("Prezzo: ");
        scanf("%lf", &a[i].prezzo);
        printf("Anno immatricolazione: ");
        scanf("%d", &a[i].annoImmatricolazione);
        printf("Targa: ");
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
    return indice; //Ritorna l'indice dell'auto col prezzo più alto
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

void visualizza(struct Auto a[], int nAuto){
    for(int i = 0; i < nAuto; i++){
        printf("Macchina numero: %d\n",i);
        printf("Modello auto: %s\n, Marca: %s\n, Cilindrata: %d\n, Prezzo: %lf\n, Anno di immatricolazione: %d\n, Targa: %s\n",a[i].modelloAuto, a[i].marca, a[i].cilindrata, a[i].prezzo, a[i].annoImmatricolazione, a[i].targa);
        printf("----------------------");
    }
}

void visualizzaAPartireDaUnPrezzo(struct Auto a[], int nAuto, double prezzo){
    for(int i = 0; i < nAuto; i++){
        if(a[i].prezzo >= prezzo){
            printf("Modello Auto: %s",a[i].modelloAuto);
        }
    }
}

int main(){
    int nAuto;
    int esci = 1;
    
    struct Auto collezioneAuto [100];
    do{

        printf("1.Inserimento \n 2.Visualizza \n 3.Prezzo più alto e prezzo più basso \n 4.Ordina lista in base all'anno di immatricolazione \n 
        5.Visualizza le auto a partire da un prezzo \n 6.Cerca un auto \n 7.Media dei prezzi \n 8.Visualizza auto in base all'anno di immatricolazione \n 9.Esci");

        int scelta;
        scanf("%d",&scelta);

    switch(scelta){
        case 1:
            printf("Quante auto vuoi inserire?");
            scanf("%d",&nAuto);
            inserimentoAuto(collezioneAuto, nAuto);
        break;

        case 2:
            visualizza(collezioneAuto, nAuto);
        break;

        case 3:
            int max = prezzoPiuAlto(collezioneAuto, nAuto);
            int min = prezzoPiuBasso(collezioneAuto, nAuto);
            printf("Auto con prezzo più alto: %s",collezioneAuto[max].modelloAuto);
            printf("Auto con prezzo più basso: %s",collezioneAuto[min].modelloAuto);
        break;

        case 4:

        break;

        case 5:
            double prezzo;
            printf("Inserisci un prezzo da cui visualizzare le auto");
            scanf("%lf",&prezzo);
            visualizzaAPartireDaUnPrezzo(collezioneAuto, nAuto, prezzo);
        break;

        case 6:
                
        break;

        case 7:

        break;

        case 8:

        break;

        case 9:
            printf("Uscita ...");
            esci = 0;
        break;
    }

    }while(esci == 1);
    
    return 0;
}
