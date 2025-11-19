// Il client invia una stringa
// Il server restituisce la stringa in cui le vocali sono sostituite dalla lettera X.

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

int main()
{

    struct sockaddr_in servizio;
    char stringa[20];
    int socketfd, soa, fromlen = sizeof(servizio);

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);

    return 0;
}