'''4️⃣ Ordini in una pizzeria
Obiettivo
Realizzare un’applicazione client–server per la gestione degli ordini di una pizzeria.Requisiti del server
gestire un menu con prezzi;
ricevere l’ordine dal client;
calcolare il totale;
applicare eventuali promozioni.
Versione (console)
scelta delle pizze tramite menu testuale;
inserimento quantità;
stampa del totale ordine.
Versione
menu visuale delle pizze;
selezione tramite checkbox o liste;
visualizzazione del conto finale.
Gestione degli errori
quantità ≤ 0;
input non numerici;
prodotti non validi.'''

import socket
import tkinter as tk
from tkinter import messagebox

def connessione ():
  client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
  client.connect(("localhost",12345))
  return client

def ricevi_pizze (client):
  data = client.recv(1024).decode()
  lista = data.split(",")
  return lista

def acquista ():
  pizza = pizza_var.get()
  numero = entry_numero.get()

  if numero == "":
    messagebox.showerror("Errore", "Numero non valido")
    return
  
  messaggio = pizza + "," + numero
  client.sendall(messaggio.encode())

  risposta = client.recv(1024).decode()
  messagebox.showinfo("Riepilogo acquisto", risposta)
  entry_numero.delete(0, tk.END)


client = connessione()
pizze = ricevi_pizze(client)

#GUI
root = tk.Tk()
root.title("Pizzeria")

pizza_var = tk.StringVar(root)
pizza_var.set(pizze[0])

tk.Label(root, text= "Seleziona pizza").pack(pady= 5)
tk.OptionMenu(root, pizza_var, *pizze).pack(pady=5)

tk.Label(root, text="Inserisci numero di pizze").pack(pady = 5)
entry_numero = tk.Entry(root)
entry_numero.pack(pady = 5)

tk.Button(root, text= "Acquista pizze", command = acquista).pack(pady = 10)

root.mainloop()
client.close()