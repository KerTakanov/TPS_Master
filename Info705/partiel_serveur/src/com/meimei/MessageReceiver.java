package com.meimei;

import javax.jms.*;
import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;

public class MessageReceiver {
    public MessageReceiver() {
        try {
            context = new InitialContext();
            qcf = (QueueConnectionFactory) context.lookup("ConnectionFactory");
            q = (Queue) context.lookup("banque");
            qc = qcf.createQueueConnection();

            qs = qc.createQueueSession(false, Session.AUTO_ACKNOWLEDGE);

            mc = qs.createConsumer(q);
            qc.start();
        } catch (NamingException | JMSException e) {
            e.printStackTrace();
        }
    }

    public TextMessage next() {
        while(true){
            TextMessage message = null;
            try {
                message = (TextMessage) mc.receive();
            } catch (JMSException e) {
                e.printStackTrace();
            }
            return message;
        }
    }

    private Context context;
    private QueueConnectionFactory qcf;
    private Queue q;
    private QueueConnection qc;
    private QueueSession qs;
    private MessageConsumer mc;
}
