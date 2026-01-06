operazioni = ["+", "-", "*", "/"]

while True:
    print("\nCalcolatrice")
    print("Scegli un'operazione:")

    for i in range(len(operazioni)):
        print(i + 1, operazioni[i])

    print("0 Esci")

    scelta = int(input("Inserisci la scelta: "))

    if scelta == 0:
        print("Fine programma")
        break

    if scelta >= 1 and scelta <= 4:
        numero1 = float(input("Inserisci il primo numero: "))
        numero2 = float(input("Inserisci il secondo numero: "))

        if scelta == 1:
            risultato = numero1 + numero2
            print("Risultato:", risultato)

        elif scelta == 2:
            risultato = numero1 - numero2
            print("Risultato:", risultato)

        elif scelta == 3:
            risultato = numero1 * numero2
            print("Risultato:", risultato)

        elif scelta == 4:
            if numero2 != 0:
                risultato = numero1 / numero2
                print("Risultato:", risultato)
            else:
                print("Errore: divisione per zero")
    else:
        print("Scelta non valida")
