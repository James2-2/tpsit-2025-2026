#include <stdio.h>
#include <string.h>

struct Studente {
    char nome[20];
    char cognome[20];
    char matricola[20];
    char corsoDiStudio[30];
    int annoImmatricolazione;
    float mediaVoti;
    char cittaResidenza[30];
};

void inserimento(struct Studente s[], int nStudenti) {
    for (int i = 0; i < nStudenti; i++) {
        printf("\nStudente %d\n", i + 1);
        printf("Nome: ");
        scanf("%s", s[i].nome);
        printf("Cognome: ");
        scanf("%s", s[i].cognome);
        printf("Matricola: ");
        scanf("%s", s[i].matricola);
        printf("Corso di studio: ");
        scanf("%s", s[i].corsoDiStudio);
        printf("Anno di immatricolazione: ");
        scanf("%d", &s[i].annoImmatricolazione);
        printf("Media voti: ");
        scanf("%f", &s[i].mediaVoti);
        printf("Città di residenza: ");
        scanf("%s", s[i].cittaResidenza);
    }
}

void visualizzaStudente(struct Studente s[], int indice) {
    printf("\nNome: %s", s[indice].nome);
    printf("\nCognome: %s", s[indice].cognome);
    printf("\nMatricola: %s", s[indice].matricola);
    printf("\nCorso di studio: %s", s[indice].corsoDiStudio);
    printf("\nAnno di immatricolazione: %d", s[indice].annoImmatricolazione);
    printf("\nMedia voti: %.2f", s[indice].mediaVoti);
    printf("\nCittà di residenza: %s\n", s[indice].cittaResidenza);
}

void visualizzaStudenti(struct Studente s[], int nStudenti) {
    for (int i = 0; i < nStudenti; i++) {
        printf("\n--- Studente %d ---", i + 1);
        visualizzaStudente(s, i);
    }
}

int mediaMax(struct Studente s[], int n) {
    int indiceMax = 0;
    for (int i = 1; i < n; i++)
        if (s[i].mediaVoti > s[indiceMax].mediaVoti)
            indiceMax = i;
    return indiceMax;
}

int mediaMin(struct Studente s[], int n) {
    int indiceMin = 0;
    for (int i = 1; i < n; i++)
        if (s[i].mediaVoti < s[indiceMin].mediaVoti)
            indiceMin = i;
    return indiceMin;
}

void ordinaLista(struct Studente s[], int n) {
    struct Studente temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i].annoImmatricolazione > s[j].annoImmatricolazione) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

int ricercaConMatricola(struct Studente s[], int n, char matricola[]) {
    for (int i = 0; i < n; i++)
        if (strcmp(s[i].matricola, matricola) == 0)
            return i;
    return -1;
}

void visualizzaConMedia(struct Studente s[], int n, float media) {
    for (int i = 0; i < n; i++)
        if (s[i].mediaVoti >= media)
            visualizzaStudente(s, i);
}

float mediaGenerale(struct Studente s[], int n) {
    float somma = 0;
    for (int i = 0; i < n; i++)
        somma += s[i].mediaVoti;
    return somma / n;
}

void visualizzaConAnno(struct Studente s[], int n, int anno) {
    for (int i = 0; i < n; i++)
        if (s[i].annoImmatricolazione == anno)
            visualizzaStudente(s, i);
}

int main() {
    struct Studente scolaresca[50];
    int nStudenti = 0, uscita = 0, scelta;

    do {
        printf("\n\n--- MENU ---\n");
        printf("1. Inserimento studenti\n");
        printf("2. Visualizza tutti gli studenti\n");
        printf("3. Studente con media max e min\n");
        printf("4. Ordina per anno di immatricolazione\n");
        printf("5. Ricerca per matricola\n");
        printf("6. Visualizza studenti con media >= valore\n");
        printf("7. Calcola media generale\n");
        printf("8. Visualizza per anno\n");
        printf("9. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
        case 1:
            printf("Quanti studenti vuoi inserire? ");
            scanf("%d", &nStudenti);
            inserimento(scolaresca, nStudenti);
            break;

        case 2:
            visualizzaStudenti(scolaresca, nStudenti);
            break;

        case 3: {
            int max = mediaMax(scolaresca, nStudenti);
            int min = mediaMin(scolaresca, nStudenti);
            printf("\nStudente con media più alta:\n");
            visualizzaStudente(scolaresca, max);
            printf("\nStudente con media più bassa:\n");
            visualizzaStudente(scolaresca, min);
            break;
        }

        case 4:
            ordinaLista(scolaresca, nStudenti);
            printf("\nLista ordinata per anno:\n");
            visualizzaStudenti(scolaresca, nStudenti);
            break;

        case 5: {
            char matricola[20];
            printf("Inserisci matricola da cercare: ");
            scanf("%s", matricola);
            int indice = ricercaConMatricola(scolaresca, nStudenti, matricola);
            if (indice != -1)
                visualizzaStudente(scolaresca, indice);
            else
                printf("Matricola non trovata.\n");
            break;
        }

        case 6: {
            float media;
            printf("Inserisci una media minima: ");
            scanf("%f", &media);
            visualizzaConMedia(scolaresca, nStudenti, media);
            break;
        }

        case 7:
            printf("Media generale: %.2f\n", mediaGenerale(scolaresca, nStudenti));
            break;

        case 8: {
            int anno;
            printf("Inserisci anno di immatricolazione: ");
            scanf("%d", &anno);
            visualizzaConAnno(scolaresca, nStudenti, anno);
            break;
        }

        case 9:
            uscita = 1;
            printf("Uscita...\n");
            break;

        default:
            printf("Scelta non valida!\n");
        }

    } while (uscita == 0);

    return 0;
}