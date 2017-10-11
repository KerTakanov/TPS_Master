package pubsub;

import org.exolab.jms.config.Subscriber;

import javax.jms.*;
import javax.naming.Context;
import javax.naming.InitialContext;
import java.util.Scanner;

public class ReceiverTopic {
    public static void main(String[] args) throws Exception{
        Context context = new InitialContext();

        TopicConnectionFactory tcf = (TopicConnectionFactory) context.lookup("ConnectionFactory");
        Topic t = (Topic) context.lookup("Info705");
        TopicConnection tc = tcf.createTopicConnection();

        TopicSession ts = tc.createTopicSession(false, Session.AUTO_ACKNOWLEDGE);

        //On créé le subscriber avec les données qu'il donne
        System.out.print("Nom du subscriber: ");
        Scanner scan = new Scanner(System.in);
        String subName = scan.nextLine().trim();
        TopicSubscriber sub = ts.createDurableSubscriber(t, subName);

        tc.start();

        while(true){
            TextMessage message = (TextMessage) sub.receive();
            System.out.println("Message reçu de la part du topic \"" + t.getTopicName() + "\"\n=>" + message.getText());
        }
    }
}
