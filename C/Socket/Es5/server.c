#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define SERVERPORT 1450
#define DIM 20

int controlloStringhe(char s[], char s2[]) {
    if (strlen(s) > strlen(s2))
        return 1;
    else if (strlen(s) < strlen(s2))
        return 0;
    else
        return -1;
}

int main() {
    struct sockaddr_in servizio;
    int socketfd, soa;
    char s[DIM], s2[DIM], risposta[DIM];
    socklen_t fromlen = sizeof(servizio);

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);

    if ((socketfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    if (bind(socketfd, (struct sockaddr*)&servizio, sizeof(servizio)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(socketfd, 10) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Server in ascolto...\n");

    for (;;) {
        soa = accept(socketfd, (struct sockaddr*)&servizio, &fromlen);
        if (soa == -1) {
            perror("accept");
            continue;
        }

        read(soa, s, DIM);
        read(soa, s2, DIM);

        int controllo = controlloStringhe(s, s2);

        if (controllo == 1)
            snprintf(risposta, DIM, "La stringa 1 è più lunga.");
        else if (controllo == 0)
            snprintf(risposta, DIM, "La stringa 2 è più lunga.");
        else
            snprintf(risposta, DIM, "Le stringhe sono uguali.");

        write(soa, risposta, DIM);

        close(soa);
    }
    return 0;
}
