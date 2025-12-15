# commento
'''
commento su più righe e Docstring
'''
# python è un linguaggio interpretato: il codice viene eseguito
# riga per riga non nella sua interezza (compilatore)
print("Ciao") # print() serve per stampare a schermo

print(5+3) # stampo direttamente la somma di due numeri
# variabili: è un contenitore di dati (testi, numeri, caratteri, etc...)
# è un nome che fa riferimento a un valore salvato in memoria

'''
NB: Python è un linguaggio non tipizzato

Come si fa a tipizzare in python:
nome_variabile : tipo_di_dato = valore
es: numero: int = 18

Tipi di dato principali in python:
int -> numeri interi
float -> numeri decimali
str -> stringhe (testi, caratteri)
bool -> True/False

Cast: (conversione di tipo di dato)
x = "10"
y = int(x)
'''

x = "10" # inizialmente è una stringa
y = int(x) # conversione ad intero
print(y + 4)

# input() serve per leggere quello che viene scritto su console
# NB: Legge sempre una stringa
nome = input("Come ti chiami: ") # legge la stringa da input
eta = int(input("Quanti anni hai: ")) # legge la stringa e la converte in intero

# f-string (format string): si scrive una f davanti a tutto e 
# si mettono le variabili all'interno delle graffe
print(f"Ciao {nome}, hai {eta} anni")

print("Ciao", nome, "hai", eta) # se utilizzo la virgola per unire le stringhe/numeri
# non devo fare il casting

# print("Ciao "+ nome + "hai " + int(eta)) # se utilizzo il + per concatenare 
# le stringhe devo fare il casting


# NB: stringhe: sono viste come "vettori", che accedo ad ogni carattere
# attraverso un indice testo[indice] se vado verso destra
# altrimenti utilizzo testo [-indice] se vado verso sinistra

testo = "Ciao"
print(testo[0])
print(testo[1])
print(testo[2])
print(testo[3])

print(testo[-0])
print(testo[-3])
print(testo[-2])
print(testo[-1])

# estrapolazione della sottostringa
testo2 = "Arianna"
fraseMeta = testo[0:2] # dal primo indice all'ultimo non compreso
print(fraseMeta)

