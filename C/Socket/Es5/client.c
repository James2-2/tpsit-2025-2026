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

int main()
{
    struct sockaddr_in = servizio;
    int socketfd, fromlen = sizeof(servizio);
    char s [DIM], s2 [DIM], risposta[DIM];
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
    
    printf("Inserisci la prima stringa: \n");
    scanf("%s",s);
    
    printf("Inserisci la seconda stringa: \n");
    scanf("%s",s2);
    
    write(socketfd, s, sizeof(s));
    write(socketfd, s2, sizeof(s2));
    
    read(socketfd, risposta, sizeof(risposta));
    
    printf("%s",risposta);
    
    close(socketfd);
    
    return 0;
}
