import socket

HOST = "127.0.0.1"
PORT = 5000

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((HOST, PORT))

while True:
    numero = input("Inserisci un numero (1-100): ")
    client.send(numero.encode())

    risposta = client.recv(1024).decode()
    print("Server:", risposta)

    if risposta == "Hai vinto":
        break

client.close()
