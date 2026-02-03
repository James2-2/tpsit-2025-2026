import socket

host = "127.0.0.1"
port = 12347

disponibilita = 10

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((host, port))
server.listen(5)

print("Server in ascolto...")
conn, addr = server.accept()
print("Client connesso:", addr)

while True:
    dati = conn.recv(1024).decode() # Ricevo le due città in una variabile unica
    if not dati:
        break

    try:
        citta_partenza, citta_arrivo = dati.split(",") # Separo le due città assegnando il valore alla propria variabile
    except ValueError:
        conn.send("Errore nell'inserimento dei dati".encode())
        continue

    if citta_partenza.isalpha() and citta_arrivo.isalpha():
        if disponibilita > 0:
            disponibilita -= 1
            print("Taxi disponibili:", disponibilita)
            risposta = "Taxi disponibile"
        else:
            risposta = "Nessun taxi disponibile"
            conn.send(risposta.encode())
            break
    else:
        risposta = "Errore nell'inserimento dei dati"

    conn.send(risposta.encode())

conn.close()
server.close()