import java.util.Scanner;

import Utility.Tools;

/**
 * Classe principale che gestisce l'applicazione GestoreTesti.
 * Fornisce un menu interattivo per eseguire varie operazioni su una frase.
 *
 * @author Giacomo Redi
 * @version 1.0
 */

public class Main {
    /**
     * Metodo principale che avvia l'applicazione.
     * Gestisce il menu interattivo e coordina tutte le operazioni sul testo.
     *
     * @param args argomenti da riga di comando
     */

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        GestoreTesti gestore = new GestoreTesti();
        boolean esci = false;
        String frase = "";

        String[] opzioni = {"Gestore Testi", "Inserisci Frase", "Visualizza lunghezza frase", "Verifica se è presente una parola",
                "Sostituisci parola", "Conta vocali e consonanti", "Inverti frase", "Estrai una porzione di frase", "Esci"};

        do {

            int scelta = Tools.Menu(opzioni, sc);

            switch (scelta) {
                case 1:
                    System.out.println("Inserisci una nuova frase:");
                    frase = gestore.inserisciFrase(sc);
                    break;

                case 2:
                    if (frase.isEmpty()) {
                        System.out.println("Devi prima inserire una frase");
                    } else {
                        System.out.println("La lunghezza della frase è: " + gestore.lunghezzaFrase(frase));
                    }
                    break;

                case 3:
                    if (frase.isEmpty()) {
                        System.out.println("Devi prima inserire una frase");
                    } else {
                        System.out.println("Inserisci la parola da cercare:");
                        String parola = sc.nextLine();
                        int pos = gestore.cercaParola(frase, parola);
                        if (pos >= 0)
                            System.out.println("La parola " + parola + " è presente in posizione " + pos);
                        else
                            System.out.println("La parola " + parola + "non è presente nella frase.");
                    }
                    break;

                case 4:
                    if (frase.isEmpty()) {
                        System.out.println("Devi prima inserire una frase");
                    } else {
                        System.out.println("Inserisci la parola da sostituire:");
                        String parola = sc.nextLine();
                        System.out.println("Inserisci la nuova parola:");
                        String nuova = sc.nextLine();
                        frase = gestore.sostituisciParola(frase, parola, nuova);
                        System.out.println("Frase aggiornata: " + frase);
                    }
                    break;

                case 5:
                    if (frase.isEmpty()) {
                        System.out.println("Devi prima inserire una frase");
                    } else {
                        int vocali = gestore.contaVocali(frase);
                        int consonanti = gestore.contaConsonanti(frase);
                        System.out.println("Vocali: " + vocali + ", Consonanti: " + consonanti);
                    }
                    break;

                case 6:
                    if (frase.isEmpty()) {
                        System.out.println("Devi prima inserire una frase");
                    } else {
                        System.out.println("Frase invertita: " + gestore.invertiFrase(frase));
                    }
                    break;

                case 7:
                    if (frase.isEmpty()) {
                        System.out.println("Devi prima inserire una frase");
                    } else {
                        System.out.println("Inserisci indice iniziale:");
                        int inizio = sc.nextInt();
                        System.out.println("Inserisci indice finale:");
                        int fine = sc.nextInt();
                        sc.nextLine(); // pulisci buffer
                        System.out.println("Porzione estratta: " + gestore.estraiPorzione(frase, inizio, fine));
                    }
                    break;

                case 8:
                    System.out.println("Uscita dal programma...");
                    esci = true;
                    break;

                default:
                    System.out.println("Scelta non valida. Riprova!");
            }

        } while (!esci);
    }
}
