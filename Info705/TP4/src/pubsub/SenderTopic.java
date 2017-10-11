package pubsub;

import javax.jms.*;
import javax.naming.Context;
import javax.naming.InitialContext;
import java.util.UUID;

public class SenderTopic {
    public static void main(String[] args) throws Exception {
        Context context = new InitialContext();

        TopicConnectionFactory tcf = (TopicConnectionFactory) context.lookup("ConnectionFactory");
        Topic t = (Topic) context.lookup("Info705");
        TopicConnection tc = tcf.createTopicConnection();

        TopicSession ts = tc.createTopicSession(false, Session.AUTO_ACKNOWLEDGE);

        MessageProducer mp = ts.createPublisher(t);
        tc.start();

        while(true)
        {
            Thread.sleep(1000);
            TextMessage message = ts.createTextMessage();
            message.setText("Message [" + UUID.randomUUID() + "]");
            mp.send(message);
            System.out.println("Written \"" + message.getText() + "\" in topic \"" + t.getTopicName() + "\".");
        }
    }
}
