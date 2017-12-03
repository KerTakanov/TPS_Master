package com.meimei;

import javax.jms.JMSException;
import java.util.Scanner;

public class ActionChoisir {
    public static Compte ChoisirCompte() throws JMSException {
        Scanner in = new Scanner(System.in);
        System.out.println("Identifiant du compte: ");
        String id = in.next();

        Main.ms.Send("get " + id);
        int solde = Integer.parseInt(Main.mr.next().getText());

        return new Compte(id, solde);
    }
}
