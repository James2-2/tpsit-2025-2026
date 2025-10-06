package Utility;

import java.util.Scanner;

/**
 * Classe di utilità che fornisce metodi statici per operazioni comuni.
 * Include funzionalità per la gestione del menu, pulizia dello schermo e attese.
 *
 * @author Giacomo Redi
 * @version 1.0
 */
public class Tools {
    /*public static void main(String[] args) {

    }*/
    private Tools() {
    }

    ; //impedisce di istanziare la classe

    public static void clrScr() {
        try {
            new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * Metodo che mette in pausa l'esecuzione per un determinato numero di millisecondi.
     *
     * @param attesa il numero di millisecondi di attesa
     */
    public static void Wait(int attesa) {
        try {
            Thread.sleep(attesa);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    /**
     * Visualizza un menu interattivo e restituisce la scelta dell'utente.
     *
     * @param opzioni array di stringhe contenente le opzioni del menu
     * @param tastiera l'oggetto Scanner per l'input dell'utente
     * @return la scelta dell'utente
     */
    public static int Menu(String[] opzioni, Scanner tastiera) {// parametri formali
        int scelta;

        do {
            clrScr();
            System.out.println("------------------");
            System.out.println(opzioni[0]);
            System.out.println("------------------");
            for (int i = 1; i < opzioni.length; i++) {
                System.out.println("[" + i + "]" + " " + opzioni[i]);
            }
            scelta = (Integer.parseInt(tastiera.nextLine()));
            //tastiera.nextLine();
            if ((scelta < 1) || (scelta > opzioni.length - 1)) {
                System.out.println("Opzione Sbagliata");
                Wait(2000);
            }
        }
        while ((scelta < 1) || (scelta > opzioni.length - 1));
        //tastiera.nextLine();
        return scelta;
    }

}