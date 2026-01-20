import socket
import tkinter as tk
from tkinter import messagebox

HOST = "127.0.0.1"
PORT = 5000

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((HOST, PORT))

def invia_tentativo():
    tentativo = entry.get()

    if not tentativo.isdigit():
        messagebox.showerror("Errore", "Inserisci un numero valido")
        return

    client.send(tentativo.encode())
    risposta = client.recv(1024).decode()

    text_area.insert(tk.END, f"Tentativo: {tentativo}\n")
    text_area.insert(tk.END, f"Risposta: {risposta}\n\n")

    entry.delete(0, tk.END)

    if risposta == "Hai vinto":
        messagebox.showinfo("Complimenti", "Hai indovinato il numero!")
        client.close()
        root.destroy()

# GUI
root = tk.Tk()
root.title("Indovina il numero")

tk.Label(root, text="Inserisci un numero (1-100):").pack(pady=5)

entry = tk.Entry(root)
entry.pack(pady=5)

btn = tk.Button(root, text="Prova", command=invia_tentativo)
btn.pack(pady=5)

text_area = tk.Text(root, height=10, width=40)
text_area.pack(pady=5)

root.mainloop()
