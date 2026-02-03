import socket
import tkinter as tk
from tkinter import messagebox
from datetime import datetime

HOST = "127.0.0.1"
PORT = 12345

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((HOST, PORT))


def aggiungi_giorno():
    giorno = entry_giorno.get().strip()
    temp12 = entry_t12.get().strip()
    temp24 = entry_t24.get().strip()

    if not giorno or not temp12 or not temp24:
        messagebox.showwarning("Attenzione", "Compila tutti i campi")
        return

    try:
        datetime.strptime(giorno, "%d/%m/%Y") # COntrolla se la data rispetta i giorni e i mesi (da 1 a 12)
    except ValueError:
        messagebox.showerror("Errore","Data non valida.\nFormato richiesto: GG/MM/AAAA")
        return

    # Controllo temperature
    try:
        float(temp12)
        float(temp24)
    except ValueError:
        messagebox.showerror("Errore","Le temperature devono essere numeriche")
        return

    dati = f"{giorno};{temp12};{temp24}"
    client.send(dati.encode())

    label_stato.config(text="Dati inviati: " + dati)

    entry_giorno.delete(0, tk.END)
    entry_t12.delete(0, tk.END)
    entry_t24.delete(0, tk.END)


def chiudi():
    client.close()
    root.destroy()


# ===== GUI =====
root = tk.Tk()
root.title("Invio Temperature giornaliere - Stazione Meteo")
root.geometry("350x250")

tk.Label(root, text="Giorno (GG/MM/AAAA)").pack(pady=5)
entry_giorno = tk.Entry(root)
entry_giorno.pack()

tk.Label(root, text="Temperatura ore 12").pack(pady=5)
entry_t12 = tk.Entry(root)
entry_t12.pack()

tk.Label(root, text="Temperatura ore 24").pack(pady=5)
entry_t24 = tk.Entry(root)
entry_t24.pack()

tk.Button(root, text="Aggiungi giorno", command=aggiungi_giorno).pack(pady=15)

label_stato = tk.Label(root, text="")
label_stato.pack(pady=5)

tk.Button(root, text="Esci", command=chiudi).pack()

root.mainloop()