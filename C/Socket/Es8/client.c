/*Scrivere il codice in C di un’applicazione socket CLIENT–SERVER in cui il server riceve in input una stringa e, 
dopo aver effettuato gli opportuni controlli (se necessari), 
rispedisce al client il numero totale di parole presenti nella stringa.
*/
// CLIENT
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define SERVERPORT 1450
#define DIM 40

int main(){

    struct sockaddr_in servizio;
    int socketfd;
    char stringa[DIM], risposta[DIM];

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);

    socketfd = socket(AF_INET, SOCK_STREAM, 0);

    connect(socketfd, (struct sockaddr*)&servizio, sizeof(servizio));

    printf("Inserisci una stringa: ");
    scanf(" %[^\n]", stringa);

    write(socketfd, stringa, sizeof(stringa));
    read(socketfd, risposta, sizeof(risposta));

    printf("Risposta del server: %s\n", risposta);

    close(socketfd);
    return 0;
}
