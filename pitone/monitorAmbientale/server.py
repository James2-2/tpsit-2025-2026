import socket
from datetime import datetime

HOST = "127.0.0.1"
PORT = 12345

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((HOST, PORT))
server.listen(1)

print("Server in ascolto...")
conn, addr = server.accept()
print("Client connesso:", addr)

while True:
    dati = conn.recv(1024).decode()
    if not dati:
        break

    try:
        giorno, t12, t24 = dati.split(";")

        datetime.strptime(giorno, "%d/%m/%Y")

        print(f"Giorno: {giorno} | T12: {t12} | T24: {t24}")

    except ValueError:
        print("Errore: formato dati o data non valida")

conn.close()
server.close()