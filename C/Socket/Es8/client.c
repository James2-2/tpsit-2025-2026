/*Scrivere il codice in C di un’applicazione socket CLIENT–SERVER in cui il server riceve in input una stringa e, 
dopo aver effettuato gli opportuni controlli (se necessari), 
rispedisce al client il numero totale di parole presenti nella stringa.
*/

#include <stdio.h>

#define SERVERPORT 1450
#define DIM 40

int main()
{
    struct sockaddr_in servizio;
    int socketfd, fromlen = sizeof(servizio);
    char[DIM] stringa, risposta[DIM];
    
    
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    
    if((socketfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        printf("Chiamata fallita alla system call socket");
        exit(1);
    }
    
    if(connect(socketfd, (struct sockaddr*)&servizio, sizeof(servizio)) == -1){
        printf("Chiamata fallita alla system call connect");
        exit(1);
    }
    
    printf("Inserisci una stringa");
    scanf("%s", stringa);
    
    write(socketfd, stringa, sizeof(stringa));
    read(socketfd, risposta, sizeof(risposta));
    
    printf("Risposta del server: %s", risposta);
    
    close(socketfd);
    
    return 0;
}