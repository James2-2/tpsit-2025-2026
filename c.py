'''Scrivere un applicazione client-Server che permetta di verificare la disponibilità di un taxi per un eventuale prenotazione:
Lato Server: la centrale dovrà rispondere al client informandolo dell'eventuale disponibilità (disponibilità rappresentata attraverso una variabile intera  ed inizializzata ad esempio a 10. 
Lato Client si dovrà effettuare una richiesta al server indicando città di partenza e città di arrivo).
Si realizzi il codice in linguaggio Python con controlli di errore ed eventuali implementazione aggiuntive. 
Lavoro da eseguire utilizzando la lan locale.'''

import socket

host = "172.0.0.1"
port = 12345

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((host, port))

while True:
    citta_partenza = input("Inserisci la città di partenza:")
    citta_arrivo = input("Inserisci la città di arrivo:")
    client.send(citta_partenza.encode())
    client.send(citta_arrivo.encode())

    risposta = client.recv(1024).decode()
    print("Risposta del server:", risposta)

    if risposta == "Taxi disponibile":
        break
    else:
        break

client.close()
