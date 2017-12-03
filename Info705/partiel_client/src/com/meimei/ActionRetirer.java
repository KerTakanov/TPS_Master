package com.meimei;

import javax.jms.JMSException;
import java.util.Scanner;

public class ActionRetirer {
    public static int Retirer(Compte compte) throws JMSException {
        if (compte == null) {
            System.err.println("Vous devez choisir un compte avant d'effectuer des actions dessus !");
            return 0;
        }

        Scanner in = new Scanner(System.in);
        System.out.println("Solde à retirer: ");
        int solde = in.nextInt();

        Main.ms.Send("ret " + compte.getId() + " " + solde);
        int new_solde = Integer.parseInt(Main.mr.next().getText());

        return new_solde;
    }
}
