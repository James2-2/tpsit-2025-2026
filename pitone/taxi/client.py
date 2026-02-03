import socket

host = "127.0.0.1"
port = 12347

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((host, port))

while True:
    citta_partenza = input("Inserisci la città di partenza: ")
    citta_arrivo = input("Inserisci la città di arrivo: ")

    client.send(f"{citta_partenza},{citta_arrivo}".encode())

    risposta = client.recv(1024).decode()
    print("Risposta del server:", risposta)

    if risposta == "Nessun taxi disponibile":
        break

client.close()
print("Connessione chiusa.")