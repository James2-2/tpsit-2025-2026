import java.util.Scanner;

/**
 * Classe che fornisce metodi per la manipolazione e l'analisi di testi.
 * Offre funzionalità per gestire frasi, cercare parole, contare vocali e consonanti, ecc.
 *
 * @author Giacomo Redi
 * @version 1.0
 */

public class GestoreTesti {

    /**
     * Permette all'utente di inserire una frase tramite Scanner.
     *
     * @param sc l'oggetto Scanner utilizzato per l'input
     * @return la frase inserita dall'utente
     */
    public String inserisciFrase(Scanner sc) {
        return sc.nextLine();
    }

    /**
     * Calcola la lunghezza di una frase.
     *
     * @param frase la frase di cui calcolare la lunghezza
     * @return il numero di caratteri della frase
     */
    public int lunghezzaFrase(String frase) {
        return frase.length();
    }

    /**
     * Cerca una parola all'interno di una frase.
     *
     * @param frase la frase in cui cercare
     * @param parola la parola da cercare
     * @return la posizione della prima occorrenza della parola, -1 se non trovata
     */
    public int cercaParola(String frase, String parola) {
        if (frase.contains(parola))
            return frase.indexOf(parola);
        return -1;
    }

    /**
     * Sostituisce tutte le occorrenze di una parola con un'altra nella frase.
     *
     * @param frase la frase originale
     * @param parolaDaSostituire la parola da sostituire
     * @param nuovaParola la nuova parola da inserire
     * @return la frase con le sostituzioni applicate, o la frase originale se la parola non è presente
     */
    public String sostituisciParola(String frase, String parolaDaSostituire, String nuovaParola) {
        if (frase.contains(parolaDaSostituire)) {
            return frase.replace(parolaDaSostituire, nuovaParola);
        } else {
            System.out.println("La parola " + parolaDaSostituire + " non è presente nella frase.");
            return frase;
        }
    }

    /**
     * Converte una frase in minuscolo.
     *
     * @param frase la frase da convertire
     * @return la frase convertita in minuscolo
     */
    public String convertiInMinuscolo(String frase) {
        return frase.toLowerCase();
    }

    /**
     * Conta il numero di vocali in una frase
     *
     * @param frase la frase in cui contare le vocali
     * @return il numero di vocali presenti nella frase
     */
    public int contaVocali(String frase) {
        convertiInMinuscolo(frase);
        int contaVocali = 0;
        for (int i = 0; i < frase.length(); i++) {
            if (frase.charAt(i) == 'a' || frase.charAt(i) == 'e' || frase.charAt(i) == 'i' || frase.charAt(i) == 'o' || frase.charAt(i) == 'u') {
                contaVocali++;
            }
        }
        return contaVocali;
    }

    /**
     * Conta il numero di consonanti in una frase
     *
     * @param frase la frase in cui contare le consonanti
     * @return il numero di consonanti presenti nella frase
     */
    public int contaConsonanti(String frase) {
        convertiInMinuscolo(frase);
        int contaConsonanti = 0;
        for (int i = 0; i < frase.length(); i++) {
            if (frase.charAt(i) != 'a' && frase.charAt(i) != 'e' && frase.charAt(i) != 'i' && frase.charAt(i) != 'o' && frase.charAt(i) != 'u') {
                contaConsonanti++;
            }
        }
        return contaConsonanti;
    }

    /**
     * Inverte l'ordine dei caratteri in una frase.
     *
     * @param frase la frase da invertire
     * @return la frase invertita
     */
    public String invertiFrase(String frase) {
        String stringaInvertita = "";

        for (int i = 0; i < frase.length(); i++) {
            stringaInvertita = frase.charAt(i) + stringaInvertita;
        }

        return stringaInvertita;
    }

    /**
     * Estrae una porzione di frase tra due indici.
     *
     * @param frase la frase originale
     * @param inizio l'indice di inizio
     * @param fine l'indice di fine
     * @return la sottostringa estratta
     */
    public String estraiPorzione(String frase, int inizio, int fine) {
        return frase.substring(inizio, fine);
    }
}
