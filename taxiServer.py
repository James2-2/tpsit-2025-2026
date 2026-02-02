'''Scrivere un applicazione client-Server che permetta di verificare la disponibilità di un taxi per un eventuale prenotazione:
Lato Server: la centrale dovrà rispondere al client informandolo dell'eventuale disponibilità (disponibilità rappresentata attraverso una variabile intera  ed inizializzata ad esempio a 10. 
Lato Client si dovrà effettuare una richiesta al server indicando città di partenza e città di arrivo).
Si realizzi il codice in linguaggio Python con controlli di errore ed eventuali implementazione aggiuntive. 
Lavoro da eseguire utilizzando la lan locale.'''

import socket

host = "127.0.0.1"
port = 12347

disponibilita = 1

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((host, port))
server.listen(5)

print("Server in ascolto...")
conn, addr = server.accept()
print("Client connesso:", addr)

while True:
    citta_partenza = conn.recv(1024).decode()
    citta_arrivo = conn.recv(1024).decode()
    
    if citta_partenza.isalpha() and citta_arrivo.isalpha():
        if disponibilita > 0:
            disponibilita -= 1
            print("Taxi disponibili: ", disponibilita)
            risposta = "Taxi disponibile"
            conn.send(risposta.encode())
        else:
            risposta = "Nessun taxi disponibile"
            conn.send(risposta.encode())
            break
    else:    
        risposta = "Errore nell'inserimento dei dati"
        conn.send(risposta.encode())


conn.close()
server.close()
