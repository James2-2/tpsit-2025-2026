#include <stdio.h>
#include <string.h>

#define DIM 1024 //Dimensione massima della stringa

int main()
{
    char stringa [DIM], stringaPari[DIM], stringaDispari [DIM], stringa2[DIM], lettera;
    int trovato = 0, conteggio = 0, soloLettere = 0, contPari = 0, contDispari = 0, contDoppie = 0, contVocali = 0, contVocali2 = 0, contConsonanti = 0, contConsonanti2 = 0, doppie = 0;
    
    printf("Inserisci una stringa\n");
    scanf("%s", stringa);
    // 1) Che contenga solo lettere;
    for(int i = 0; i< strlen(stringa);i++){
        if(stringa[i]>= 'a' && stringa[i] <= 'z'){
            soloLettere++;
        }
    }
    
    if(soloLettere != strlen(stringa)){
        printf("Non contiene solo lettere");
        return 0;
    }
    
    //2) Il conteggio di una lettera (se presente) scelta dall’utente;
    printf("Quale lettera vuoi cercare?\n");
    scanf(" %c",&lettera);
    
    for(int i = 0; i < strlen(stringa);i++){
        if(stringa[i] == lettera){
            conteggio ++;
            trovato = 1;
        }
    }
    
    if(trovato == 1){
        printf("La lettera %c è presente %d volta/e\n",lettera,conteggio);
    }else{
        printf("Lettera non trovata");
    }
    
    //3) Crei 2 ulteriori stringhe che contengano 1 le lettere di posizione pari; la 2° le lettere di posizione dispari;
    for(int i = 0; i < strlen(stringa);i++){
        if(i % 2 == 0){
            stringaPari[contPari] = stringa[i];
            contPari++;
        }else{
            stringaDispari[contDispari] = stringa[i];
            contDispari++;
        }
    }
    
    printf("Stringa con posizione pari: %s\n",stringaPari);
    printf("Stringa con posizione dispari: %s\n",stringaDispari);

    //4) Verifichi se contiene doppie.
    for(int i = 0; i < strlen(stringa);i++){
        for(int j = i +1; j<strlen(stringa); j++){
            if(stringa[i] == stringa[j]){
                doppie = 1;
            }
        }
    }
    
    if(doppie == 1){
        printf("Sono presenti doppie\n");
    }else{
        printf("Non sono presenti doppie\n");
    }

    printf("Inserisci una seconda stringa\n");
    scanf("%s", stringa2);
    
    //1) Quale delle 2 è più lunga e più corta;
    if(strlen(stringa) > strlen(stringa2)){
        printf("La stringa 1 è piu lunga della stringa 2\n");
    }else if(strlen(stringa) > strlen(stringa2)){
        printf("La stringa 2 è piu lunga della stringa 1\n");
    }else{
        printf("Le stringhe sono lunghe uguali\n");
    }
    
    //2) Quali sono le lettere contenute in ambedue le stringhe;
    char lettereComuni[DIM];
    int a = 0;
    
    for(int i = 0; i < strlen(stringa);i++){
        for(int j = 0; j<strlen(stringa2); j++){
            if(stringa[i] == stringa2[j]){
                lettereComuni[a] = stringa[i];
                a++;
            }
        }
    }
    
    printf("Le lettere comuni tra le due stringhe sono: %s\n",lettereComuni);
    
    //3) Quale delle 2 stringhe contiene più vocali;
    for(int i = 0; i < strlen(stringa);i++){
        if(stringa[i] == 'a' || stringa[i] == 'e' || stringa[i] == 'i' || stringa[i] == 'o' || stringa[i] == 'u'){
            contVocali++;
        }
    }
    
    for(int i = 0; i < strlen(stringa2);i++){
        if(stringa2[i] == 'a' || stringa2[i] == 'e' || stringa2[i] == 'i' || stringa2[i] == 'o' || stringa2[i] == 'u'){
            contVocali2++;
        }
    }
    
    if(contVocali > contVocali2){
        printf("La prima stringa contiene più vocali\n");
    }else if(contVocali < contVocali2){
        printf("La seconda stringa contiene più vocali\n");
    }else{
        printf("Le stringhe hanno la stessa quantità di vocali\n");
    }
    
    //4) Quale delle 2 stringhe contiene più consonanti;
    for(int i = 0; i < strlen(stringa);i++){
        if(stringa[i] != 'a' && stringa[i] != 'e' && stringa[i] != 'i' && stringa[i] != 'o' && stringa[i] != 'u'){
            contConsonanti++;
        }
    }
    
    for(int i = 0; i < strlen(stringa2);i++){
        if(stringa2[i] != 'a' && stringa2[i] != 'e' && stringa2[i] != 'i' && stringa2[i] != 'o' && stringa2[i] != 'u'){
            contConsonanti2++;
        }
    }
    
    if(contConsonanti > contConsonanti2){
        printf("La prima stringa contiene più consonanti");
    }else if(contConsonanti < contConsonanti2){
        printf("La seconda stringa contiene più consonanti");
    }else{
        printf("Le stringhe hanno la stessa quantità di consonanti");
    }

    return 0;
}
