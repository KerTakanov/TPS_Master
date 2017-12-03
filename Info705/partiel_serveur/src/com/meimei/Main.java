package com.meimei;

import javax.jms.*;
import javax.naming.Context;
import javax.naming.InitialContext;
import java.util.HashMap;

public class Main {

    public static void main(String[] args) throws JMSException, InterruptedException {
        HashMap<String, Compte> comptes = new HashMap<>();
        MessageSender ms = new MessageSender();
        MessageReceiver mr = new MessageReceiver();

        while (true) {
            String msg = mr.next().getText();
        }
    }
}
