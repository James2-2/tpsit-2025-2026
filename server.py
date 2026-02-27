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
import threading

lock = threading.Lock()

pizze = {
  "Margherita":{"prezzo": 6}
  
}

def gestione_client (conn, addr):
  print(f"Connessione con {addr}")
  lista_pizze = ",".join(pizze.keys())
  conn.sendall(lista_pizze.encode())

  while True:
    