package com.meimei;

import javax.jms.*;
import javax.naming.Context;
import javax.naming.InitialContext;

public class Main {
    public static MessageReceiver mr;
    public static MessageSender ms;

    public static void main(String[] args) throws JMSException, InterruptedException {
        mr = new MessageReceiver();
        ms = new MessageSender();
        Compte compte = null;

        Menu.Choix choix = Menu.GetAnswer();
        while (choix != Menu.Choix.QUITTER) {
            switch (choix) {
                case CHOISIR:
                    compte = ActionChoisir.ChoisirCompte();
                    break;
                case AJOUTER:
                    ActionAjouter.Ajouter(compte);
                    break;
                case RETIRER:
                    ActionRetirer.Retirer(compte);
                    break;
                case AFFICHER:
                    ActionAfficher.Afficher(compte);
                    break;
            }

            choix = Menu.GetAnswer();
        }
    }
}
