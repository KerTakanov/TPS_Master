package com.meimei;

import java.util.Scanner;

public class Menu {
    public enum Choix {
        CHOISIR,
        AJOUTER,
        RETIRER,
        AFFICHER,
        QUITTER
    }

    private static void Show() {
        System.out.println("1 - Choisir un compte bancaire");
        System.out.println("2 - Ajouter une somme au compte");
        System.out.println("3 - Retirer un somme du compte");
        System.out.println("4 - Afficher le solde du compte");
        System.out.println("5 - Quitter le programme");
    }

    private static int Get() {
        Scanner in = new Scanner(System.in);
        System.out.print("=> ");
        return in.nextInt();
    }

    public static Choix GetAnswer() {
        Menu.Show();
        int answer = Menu.Get();
        while (answer < 0 || answer > Choix.QUITTER.ordinal()) {
            if (answer < 0 || answer > Choix.QUITTER.ordinal()) {
                System.out.println("Vous devez entrer un choix entre 0 et " + Choix.QUITTER.ordinal());
            }
            answer = Menu.Get();
        }

        return Choix.values()[answer];
    }
}
