package ftp;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

/**
 * Notre serveur FTP utilisant GetFile et PutFile, a comme premier argument le port (int), et en deuxième le chemin vers
 * le répertoire racine (string)
 */
public class Server {
    public static void main(String args[]) {
        try {
            // On récupère le port et le chemin du répertoire racine
            int port = Integer.parseInt(args[0]);
            String root = args[1];

            // On créé nos objets permettant la manipulation de nos fichiers
            GetFile getFile = new GetFile();
            PutFile putFile = new PutFile();

            // Création du registre
            Registry registry = LocateRegistry.createRegistry(1099);

            // Création des stubs
            IGetFile getfile_stub = (IGetFile) UnicastRemoteObject.exportObject(getFile, 0);
            IPutFile putfile_stub = (IPutFile) UnicastRemoteObject.exportObject(putFile, 0);

            // On lie nos objets à notre registre afin que le client y aie accès
            registry.bind("get", getfile_stub);
            registry.bind("put", putfile_stub);

            System.err.println("Server ready");
        } catch (Exception e) {
            System.err.println("Server exception: " + e.toString());
            e.printStackTrace();
        }
    }
}
