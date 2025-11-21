/*Esercizio 5
Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve in input 2
stringhe e, dopo aver effettuato gli eventuali ed opportuni controlli (se necessari), rispedisce al Client il
messaggio di quale delle due stringhe è + lunga o più corta o se sono uguali.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

#define SERVERPORT 1450
#define DIM 20

int controlloStringhe(char s[], char s2[]){
    if(strlen(s) > strlen(s2)){
        return 1;
    }else if(strlen(s) < strlen(s2)){
        return 0;
    }else {
        return -1;
    }
}

int main()
{
    struct sockaddr_in = servizio;
    int socketfd, soa, fromlen = sizeof(servizio);
    char s [DIM], s2 [DIM];
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    
    if((socketfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        printf("Chiamata fallita alla system call socket");
        exit(0);
    }
    
    if((bind(socketfd, (struct sockaddr*)&servizio, &fromlen)) == -1){
        printf("Chiamata fallita alla system call bind");
        exit(0);
    }
    
    if((listen(socketfd, 10)) == -1){
        printf("Chiamata fallita alla system call listen");
        exit(0);
    }
    
    for(;;){
        printf("Server in ascolto");
        
        if((soa = accept(socketfd, (struct sockaddr*)&servizio, &fromlen)) == -1){
            printf("Chiamata fallita alla system call accept");
            exit(0);
        }
        
        read(soa, s, sizeof(s));
        printf("Stringa ricevuta %s",s);
        
        read(soa, s2, sizeof(s2));
        printf("Stringa ricevuta %s",s2);
        
        int controllo = controlloStringhe(s, s2);
        
        char risposta[DIM];
        
        if(controllo == 1){
            sprintf(risposta, sizeof(risposta), "La stringa 1 è più lunga.");
        } else if(controllo == 0){
            sprintf(risposta, sizeof(risposta), "La stringa 2 è più lunga.");
        } else {
            sprintf(risposta, sizeof(risposta), "Le due stringhe sono uguali.");
        }
        
        write(socketfd, risposta, sizeof(risposta));
        
        close(soa);
    }
    
    return 0;   
}
