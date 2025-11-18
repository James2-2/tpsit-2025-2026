/*Esercizio 2
Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve in input 1 stringa
e un carattere, e dopo aver effettuato gli eventuali ed opportuni controlli (se necessari), rispedisce al Client il
numero di occorrenze del carattere nella stringa.
*/

// SERVER

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

#define DIM 50
#define SERVERPORT 1450

int contaOccorrenze (char s [], char c){
    int contaOccorrenze = 0;
    for(int i = 0; i< strlen(s); i++){
        if(s[i] == c){
            contaOccorrenze ++;
        }
    }
    return contaOccorrenze;
}

int main (){
    struct sockaddr_in servizio, addr_remoto;
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    int socketfd, soa, fromlen = sizeof(servizio);
    char s [DIM], c, response[DIM];
    
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(socketfd, (struct sockaddr*)&servizio, sizeof(servizio));
    listen(socketfd, 10);
    
    for(;;){
        printf("Server in ascolto...\n");
        fflush(stdout);
        
        soa = accept(socketfd, (struct sockaddr*)&addr_remoto, &fromlen);
        read(soa,s, sizeof(s));
        printf("Stringa ricevuta: %s\n");
        read(soa, &c, 1);
        printf("Carattere ricevuto: %c\n");
        
        if(contaOccorrenze > 0){
            printf("Il carattere è presente %d volta/e",contaOccorrenze(s, c));
        }else{
            printf("Il carattere non è presente nella parola");
        }
        
        printf("Invio risposta al client... %s", response);
        write(soa, response, sizeof(response));
        close(soa);
    }
    
    return 0;
}
