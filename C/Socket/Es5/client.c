#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define SERVERPORT 1450
#define DIM 20

int main() {
    struct sockaddr_in servizio;
    int socketfd;
    char s[DIM], s2[DIM], risposta[DIM];

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);

    if ((socketfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    if (connect(socketfd, (struct sockaddr*)&servizio, sizeof(servizio)) == -1) {
        perror("connect");
        exit(1);
    }

    printf("Inserisci la prima stringa: ");
    scanf("%s", s);

    printf("Inserisci la seconda stringa: ");
    scanf("%s", s2);

    write(socketfd, s, DIM);
    write(socketfd, s2, DIM);

    read(socketfd, risposta, DIM);

    printf("Risposta del server: %s\n", risposta);

    close(socketfd);
    return 0;
}
