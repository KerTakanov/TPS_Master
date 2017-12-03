package com.meimei;

import javax.jms.*;
import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;

public class MessageSender {
    public MessageSender() throws InterruptedException, JMSException {
        try {
            context = new InitialContext();
            qcf = (QueueConnectionFactory) context.lookup("ConnectionFactory");
            q = (Queue) context.lookup("banque");
            qc = qcf.createQueueConnection();

            qs = qc.createQueueSession(false, Session.AUTO_ACKNOWLEDGE);

            mp = qs.createProducer(q);
            qc.start();
        } catch (NamingException | JMSException e) {
            e.printStackTrace();
        }
    }

    public void Send(String content) {
        try {
            TextMessage message = qs.createTextMessage();
            message.setText(content);
            mp.send(message);
        } catch (JMSException e) {
            e.printStackTrace();
        }
    }

    private Context context;
    private QueueConnectionFactory qcf;
    private Queue q;
    private QueueConnection qc;
    private QueueSession qs;
    private MessageProducer mp;
}
