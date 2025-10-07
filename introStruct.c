#include <stdio.h>

//Definizione della struttura per rappresentare una persona
struct Persona{
    char nome [50];
    char cognome [50];
    int eta;
    float altezza;
};

/*
typedef struct{
    char nome [50];
    char cognome [50];
    int eta;
    float altezza;
} Persona;
*/

void stampaDettagliPersona(struct Persona p){
    printf("Dettagli della persona: \n");
    printf("Nome %s\n", p.nome);
    printf("Cognome %s\n", p.cognome);
    printf("Età %d\n", p.eta);
    printf("Altezza %.2f\n", p.altezza);
}

void aggiornaEta(struct Persona *p, int nuovaEta){
    (*p).eta = nuovaEta;
}

int main(){

    struct Persona persona1 = {"Luigi", "Verdi", 25, 1.80}; // Se uso il primo metodo
    //Persona persona1; //Se uso il secondo metodo
    struct Persona persona1[10];

    stampaDettagliPersona(persona1);
    aggiornaEta(&persona1, 42);
    printf("Età ora: %d", persona1.eta);
    
    for(int i = 0; i< 10; i++){
        printf("Inserimento dati");
        printf("Nome: ");
        scanf("%s",&p.nome);
        printf("Cognome: ");
        scanf("%s",&p.cognome);
        printf("Età: ");
        scanf("%d",&p.eta);
        printf("Altezza: ");
        scanf("%f",&p.altezza);
    }
    return 0;

}
