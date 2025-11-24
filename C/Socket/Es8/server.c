/*Scrivere il codice in C di un’applicazione socket CLIENT–SERVER in cui il server riceve in input una stringa e, 
dopo aver effettuato gli opportuni controlli (se necessari), 
rispedisce al client il numero totale di parole presenti nella stringa.
*/

#include <stdio.h>

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

int main()
{
    struct sockaddr_in servizio;
    int socketfd, fromlen = sizeof(servizio), soa;
    char[DIM] stringa, risposta[DIM];
    
    
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    
    if((socketfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        printf("Chiamata fallita alla system call socket");
        exit(1);
    }
    
    if(bind(socketfd, (struct sockaddr*)&servizio, sizeof(servizio)) == -1){
        printf("Chiamata fallita alla system call bind");
        exit(1);
    }
    
    if(listen(socketfd, 10) == -1){
        printf("Chiamata fallita alla system call listen");
        exit(1);
    }
    
    for(;;){
        printf("Server in ascolto...");
        
        if((soa = accept(socketfd, (struct sockaddr*)&servizio, sizeof(servizio))) == -1){
            printf("Chiamata fallita alla system call accept");
            exit(1);
        }
        
        read(soa, stringa, sizeof(stringa));
        printf("Stringa ricevuta: %s", stringa);
        
        int nParole = contaParole(stringa);
        
        if(nParole > 0){
            snprintf(risposta, sizeof(risposta), "Sono presenti %d parola/e", nParole);
        }else{
            snprintf(risposta, sizeof(risposta), "Non sono presenti parole");
        }
        
        write(soa, risposta, sizeof(risposta));
        close(soa);
    }
    
    
    return 0;
}