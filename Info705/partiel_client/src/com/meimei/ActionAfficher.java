package com.meimei;

import javax.jms.JMSException;
import java.util.Scanner;

public class ActionAfficher {
    public static void Afficher(Compte compte) throws JMSException {
        if (compte == null) {
            System.err.println("Vous devez choisir un compte avant d'effectuer des actions dessus !");
            return;
        }

        Main.ms.Send("get " + compte.getId());
        int solde = Integer.parseInt(Main.mr.next().getText());
        compte.setSolde(solde);
        compte.AfficherSolde();
    }
}
