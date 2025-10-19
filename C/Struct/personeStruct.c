/*
Giacomo Redi 5F 19/10/2025
Esercizio – Preparazione verifica
Scrivere un programma in C che dopo aver dichiarato una struttura denominata Persona con i
seguenti campi: Nome, Cognome, età, codice fiscale, reddito annuo, anno_nascita,residenza(città) ;
determini:
1) La persona con reddito annuo più alto e quella con reddito annuo più basso.Visualizzare
per entrambe: nome, cognome, città e reddito.
2) Ordinare la lista delle persone in base all’anno di nascita** (dal più anziano al più
giovane), e visualizzarla.
3) Consentire all’utente di cercare una persona inserendo il codice fiscale..
4) Visualizzare tutte le persone con reddito superiore o uguale a un valore scelto dall’utente.
5) Calcolare la media dei redditi delle persone registrate nel sistema.
6) Visualizzare tutte le persone nate in un anno specifico, scelto dall’utente;
*/

#include <stdio.h>
#include <string.h>

struct Persona {
    char nome[50];
    char cognome[50];
    int eta;
    char codiceFiscale[17];
    int redditoAnnuo;
    int annoNascita;
    char citta[50];
};

void inserimento(struct Persona p[], int nPersone) {
    for (int i = 0; i < nPersone; i++) {
        printf("\nInserisci la %dª persona\n", i + 1);
        printf("Nome: ");
        scanf("%s", p[i].nome);
        printf("Cognome: ");
        scanf("%s", p[i].cognome);
        printf("Età: ");
        scanf("%d", &p[i].eta);
        printf("Codice Fiscale: ");
        scanf("%s", p[i].codiceFiscale);
        printf("Reddito annuo: ");
        scanf("%d", &p[i].redditoAnnuo);
        printf("Anno di nascita: ");
        scanf("%d", &p[i].annoNascita);
        printf("Città: ");
        scanf("%s", p[i].citta);
    }
}

void visualizzaPersona(struct Persona p[], int indice) {
    printf("\nNome: %s\n", p[indice].nome);
    printf("Cognome: %s\n", p[indice].cognome);
    printf("Età: %d\n", p[indice].eta);
    printf("Codice Fiscale: %s\n", p[indice].codiceFiscale);
    printf("Reddito annuo: %d\n", p[indice].redditoAnnuo);
    printf("Anno di nascita: %d\n", p[indice].annoNascita);
    printf("Città: %s\n\n", p[indice].citta);
}

void visualizzaPersone(struct Persona p[], int nPersone) {
    for (int i = 0; i < nPersone; i++) {
        printf("\nPersona %d:", i + 1);
        visualizzaPersona(p, i);
    }
}

int redditoPiuAlto(struct Persona p[], int nPersone) {
    int indiceMax = 0;
    for (int i = 1; i < nPersone; i++) {
        if (p[i].redditoAnnuo > p[indiceMax].redditoAnnuo)
            indiceMax = i;
    }
    return indiceMax;
}

int redditoPiuBasso(struct Persona p[], int nPersone) {
    int indiceMin = 0;
    for (int i = 1; i < nPersone; i++) {
        if (p[i].redditoAnnuo < p[indiceMin].redditoAnnuo)
            indiceMin = i;
    }
    return indiceMin;
}

void ordinaPersone(struct Persona p[], int nPersone) {
    struct Persona temp;
    for (int i = 0; i < nPersone - 1; i++) {
        for (int j = 0; j < nPersone - i - 1; j++) {
            if (p[j].annoNascita > p[j + 1].annoNascita) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

int cercaConCodice(struct Persona p[], int nPersone, char codice[]) {
    for (int i = 0; i < nPersone; i++) {
        if (strcmp(p[i].codiceFiscale, codice) == 0) {
            return i;
        }
    }
    return -1;
}

void visualizzaConReddito(struct Persona p[], int nPersone, int reddito) {
    for (int i = 0; i < nPersone; i++) {
        if (p[i].redditoAnnuo >= reddito) {
            visualizzaPersona(p, i);
        }
    }
}

double mediaRedditi(struct Persona p[], int nPersone) {
    int sommaRedditi = 0;
    for (int i = 0; i < nPersone; i++) {
        sommaRedditi += p[i].redditoAnnuo;
    }
    return (double)sommaRedditi / nPersone;
}

void visualizzaConAnno(struct Persona p[], int nPersone, int anno) {
    for (int i = 0; i < nPersone; i++) {
        if (p[i].annoNascita == anno) {
            visualizzaPersona(p, i);
        }
    }
}

int main() {
    int uscita = 0;
    int scelta, nPersone = 0;
    struct Persona collezionePersone[10];

    do {
        printf("\n--- MENU ---\n");
        printf("1. Inserimento Persone\n");
        printf("2. Visualizza Persone\n");
        printf("3. Visualizza reddito più alto e più basso\n");
        printf("4. Ordina per anno di nascita (dal più anziano)\n");
        printf("5. Cerca persona per codice fiscale\n");
        printf("6. Visualizza persone con reddito \n");
        printf("7. Calcola media dei redditi\n");
        printf("8. Visualizza persone nate in un anno specifico\n");
        printf("9. Uscita\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
                printf("Quante persone vuoi inserire? ");
                scanf("%d", &nPersone);
                inserimento(collezionePersone, nPersone);
                break;

            case 2:
                visualizzaPersone(collezionePersone, nPersone);
                break;

            case 3: {
                int max = redditoPiuAlto(collezionePersone, nPersone);
                int min = redditoPiuBasso(collezionePersone, nPersone);
                printf("\nPersona con reddito più alto:\n");
                visualizzaPersona(collezionePersone, max);
                printf("Persona con reddito più basso:\n");
                visualizzaPersona(collezionePersone, min);
                break;
            }

            case 4:
                ordinaPersone(collezionePersone, nPersone);
                printf("\nPersone ordinate per anno di nascita:\n");
                visualizzaPersone(collezionePersone, nPersone);
                break;

            case 5: {
                char codice[17];
                printf("Inserisci codice fiscale: ");
                scanf("%s", codice);
                int indice = cercaConCodice(collezionePersone, nPersone, codice);
                if (indice != -1)
                    visualizzaPersona(collezionePersone, indice);
                else
                    printf("Persona non trovata.\n");
                break;
            }

            case 6: {
                int reddito;
                printf("Inserisci reddito minimo: ");
                scanf("%d", &reddito);
                visualizzaConReddito(collezionePersone, nPersone, reddito);
                break;
            }

            case 7: {
                double media = mediaRedditi(collezionePersone, nPersone);
                printf("Media dei redditi: %.2lf\n", media);
                break;
            }

            case 8: {
                int anno;
                printf("Inserisci anno di nascita: ");
                scanf("%d", &anno);
                visualizzaConAnno(collezionePersone, nPersone, anno);
                break;
            }

            case 9:
                uscita = 1;
                printf("Uscita in corso...\n");
                break;

            default:
                printf("Scelta non valida.\n");
                break;
        }
    } while (uscita == 0);

    return 0;
}
