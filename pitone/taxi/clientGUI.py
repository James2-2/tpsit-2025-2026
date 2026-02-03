import socket
import tkinter as tk
from tkinter import messagebox

host = "127.0.0.1"
port = 12347

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((host, port))

def invia():
    citta_partenza = entry_partenza.get()
    citta_arrivo = entry_arrivo.get()

    if not citta_partenza or not citta_arrivo:
        messagebox.showwarning("Attenzione", "Inserisci entrambe le città")
        return

    client.send(f"{citta_partenza},{citta_arrivo}".encode())

    risposta = client.recv(1024).decode()
    label_risposta.config(text=risposta)

    if risposta == "Nessun taxi disponibile":
        btn_invia.config(state="disabled") # Disattivo il pulsante se i taxi sono finiti

def chiudi():
    client.close()
    root.destroy()

# ===== GUI =====
root = tk.Tk()
root.title("Taxi Client")
root.geometry("300x220")

tk.Label(root, text="Città di partenza").pack(pady=5)
entry_partenza = tk.Entry(root)
entry_partenza.pack()

tk.Label(root, text="Città di arrivo").pack(pady=5)
entry_arrivo = tk.Entry(root)
entry_arrivo.pack()

btn_invia = tk.Button(root, text="Invia richiesta", command=invia)
btn_invia.pack(pady=15)

label_risposta = tk.Label(root, text="")
label_risposta.pack(pady=10)

tk.Button(root, text="Esci", command=chiudi).pack()

root.mainloop()