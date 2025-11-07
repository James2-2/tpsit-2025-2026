/*
Esercizio 3
Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve in input 1 stringa,
e dopo aver effettuato gli eventuali ed opportuni controlli (se necessari), rispedisce al Client la stringa
ordinata alfabeticamente (eliminando i caratteri speciali).
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

#define DIM 100
#define SERVERPORT 1313


// Funzione per ordinare alfabeticamente una stringa (bubble sort)
void ordina_stringa(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tolower(str[i]) > tolower(str[j])) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main()
{
    struct sockaddr_in servizio, addr_remoto;
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);

    int socketfd, soa;
    socklen_t fromlen = sizeof(addr_remoto);
    char str[DIM];
    char pulita[DIM];

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    
    bind(socketfd, (struct sockaddr*)&servizio, sizeof(servizio)) 
        
    listen(socketfd, 10);

    for (;;) {
        printf("\nServer in ascolto...\n");
        fflush(stdout);

        soa = accept(socketfd, (struct sockaddr*)&addr_remoto, &fromlen);

        read(soa, str, sizeof(str));
        printf("Stringa ricevuta: %s\n", str);

        ordina_stringa(str);

        printf("Stringa ordinata: %s\n", str);

        write(soa, str, sizeof(str));

        close(soa);
    }

    close(socketfd);
    return 0;

}
