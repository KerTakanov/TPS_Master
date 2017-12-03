package com.meimei;

import javax.jms.JMSException;
import java.util.Scanner;

public class ActionAjouter {
    public static int Ajouter(Compte compte) throws JMSException {
        if (compte == null) {
            System.err.println("Vous devez choisir un compte avant d'effectuer des actions dessus !");
            return 0;
        }

        Scanner in = new Scanner(System.in);
        System.out.println("Solde à ajouter: ");
        int solde = in.nextInt();

        Main.ms.Send("add " + compte.getId() + " " + solde);
        int new_solde = Integer.parseInt(Main.mr.next().getText());

        return new_solde;
    }
}
