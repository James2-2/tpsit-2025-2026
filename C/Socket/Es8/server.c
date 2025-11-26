/*Scrivere il codice in C di un’applicazione socket CLIENT–SERVER in cui il server riceve in input una stringa e, 
dopo aver effettuato gli opportuni controlli (se necessari), 
rispedisce al client il numero totale di parole presenti nella stringa.
*/
// SERVER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define SERVERPORT 1450
#define DIM 40

int contaParole(char stringa[]){
    int count = 1;
    for(int i=0; i< strlen(stringa); i++){
        if(stringa[i] == " "){
            count ++;
        }
    }
    return count;
}

int main(){

    struct sockaddr_in servizio, remoto;
    int socketfd, soa;
    socklen_t fromlen = sizeof(remoto);
    char stringa[DIM], risposta[DIM];

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(socketfd, (struct sockaddr*)&servizio, sizeof(servizio));
    listen(socketfd, 10);

    for(;;){
        printf("Server in ascolto...\n");

        soa = accept(socketfd, (struct sockaddr*)&remoto, &fromlen);

        read(soa, stringa, sizeof(stringa));
        printf("Stringa ricevuta: %s\n", stringa);

        int nParole = contaParole(stringa);

        snprintf(risposta, sizeof(risposta), "Sono presenti %d parola/e", nParole);

        write(soa, risposta, sizeof(risposta));
        close(soa);
    }

    return 0;
}
