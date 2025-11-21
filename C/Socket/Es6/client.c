/*Esercizio 6
Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve in input un
vettore di numeri e dopo aver effettuato gli eventuali ed opportuni controlli (se necessari), rispedisce al
Client il conteggio dei numeri pari e dei numeri dispari contenuti nel vettore.
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

int main()
{
    struct sockaddr_in = servizio;
    int socketfd, fromlen = sizeof(servizio), vet [DIM];
    char risposta[DIM];
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    
    if((socketfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        printf("Chiamata fallita alla system call socket");
        exit(0);
    }
    
    if((connect(socketfd, (struct sockaddr* )&servizio, &fromlen)) == -1){
        printf("Chiamata fallita alla system call connect");
        exit(0);
    }
    
    write(socketfd, vet, sizeof(vet));
    
    read(socketfd, risposta, sizeof(risposta));
    
    printf("%s",risposta);
    
    close(socketfd);
    
    return 0;
}
