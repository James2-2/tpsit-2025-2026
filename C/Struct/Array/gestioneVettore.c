#include <stdio.h>

#define DIM 5 //Dimensione massima dell'array

void stampaArray(int vet[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int main() {
    int vet[DIM] = {2, 4, 6, 2, 1};
    int dimensione = DIM;
    int scelta = 0;
    int somma = 0;
    float media = 0;

    do {
        printf("\n--- MENU ---\n");
        printf("1) Visualizza array\n");
        printf("2) Visualizza array invertito\n");
        printf("3) Somma e media elementi\n");
        printf("4) Visualizza numeri pari\n");
        printf("5) Visualizza numeri dispari\n");
        printf("6) Ricerca un numero\n");
        printf("7) Elimina un numero\n");
        printf("8) Alterna a due a due\n");
        printf("9) Ordina l'array\n");
        printf("0) Esci\n");
        printf("Quale operazione vuoi eseguire? ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1: {
                stampaArray(vet, dimensione);
                break;
            }
            case 2: {
                for (int i = dimensione - 1; i >= 0; i--) {
                    printf("%d ", vet[i]);
                }
                printf("\n");
                break;
            }
            case 3: {
                somma = 0;
                for (int i = 0; i < dimensione; i++) {
                    somma += vet[i];
                }
                media = (float)somma / dimensione;
                printf("Somma = %d\n", somma);
                printf("Media = %.2f\n", media);
                break;
            }
            case 4: {
                for (int i = 0; i < dimensione; i++) {
                    if (vet[i] % 2 == 0) {
                        printf("%d ", vet[i]);
                    }
                }
                printf("\n");
                break;
            }
            case 5: {
                for (int i = 0; i < dimensione; i++) {
                    if (vet[i] % 2 != 0) {
                        printf("%d ", vet[i]);
                    }
                }
                printf("\n");
                break;
            }
            case 6: {
                int numero, trovato = 0;
                printf("Numero da cercare: ");
                scanf("%d", &numero);
                for (int i = 0; i < dimensione; i++) {
                    if (vet[i] == numero) {
                        printf("Numero %d trovato in posizione %d\n", numero, i);
                        trovato = 1;
                    }
                }
                if (!trovato) {
                    printf("Numero non trovato.\n");
                }
                break;
            }
            case 7: {
                int numero, pos = -1;
                printf("Numero da eliminare: ");
                scanf("%d", &numero);
                for (int i = 0; i < dimensione; i++) {
                    if (vet[i] == numero) {
                        pos = i;
                        break;
                    }
                }
                if (pos != -1) {
                    for (int i = pos; i < dimensione - 1; i++) {
                        vet[i] = vet[i + 1];
                    }
                    dimensione--;  // riduco la dimensione logica
                    printf("Numero eliminato. Nuovo array: ");
                    stampaArray(vet, dimensione);
                } else {
                    printf("Numero non trovato.\n");
                }
                break;
            }
            case 8: {
                for (int i = 0; i < dimensione - 1; i += 2) {
                    int tmp = vet[i];
                    vet[i] = vet[i + 1];
                    vet[i + 1] = tmp;
                }
                printf("Array alternato: ");
                stampaArray(vet, dimensione);
                break;
            }
            case 9: {
                for (int i = 0; i < dimensione - 1; i++) {
                    for (int j = 0; j < dimensione - 1 - i; j++) {
                        if (vet[j] > vet[j + 1]) {
                            int tmp = vet[j];
                            vet[j] = vet[j + 1];
                            vet[j + 1] = tmp;
                        }
                    }
                }
                printf("Array ordinato: ");
                stampaArray(vet, dimensione);
                break;
            }
            case 0: {
                printf("Uscita...\n");
                break;
            }
            default:
                printf("Scelta non valida.\n");
        }
    } while (scelta != 0);

    return 0;
}
