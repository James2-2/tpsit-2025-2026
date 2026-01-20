import socket
import random

HOST = "127.0.0.1"
PORT = 5000

numero_segreto = random.randint(1, 100)
print("Numero segreto:", numero_segreto)

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((HOST, PORT))
server.listen(1)

print("Server in ascolto...")
conn, addr = server.accept()
print("Client connesso:", addr)

while True:
    data = conn.recv(1024).decode()
    if not data:
        break

    tentativo = int(data)

    if tentativo < numero_segreto:
        risposta = "Troppo basso"
    elif tentativo > numero_segreto:
        risposta = "Troppo alto"
    else:
        risposta = "Hai vinto"
        conn.send(risposta.encode())
        break

    conn.send(risposta.encode())

conn.close()
server.close()
