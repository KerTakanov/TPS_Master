package ftp;

import java.nio.charset.StandardCharsets;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

/**
 * Notre client FTP utilisant IGetFile et IPutFile afin de manipuler à distance nos fichiers.
 */
public class Client {
    private Client() {}

    public static void main(String[] args) {
        try {
            String host = args[0];
            int port = Integer.parseInt(args[1]);
            String filename = args[2];

            Registry registry = LocateRegistry.getRegistry(host);

            IGetFile getFile_stub = (IGetFile) registry.lookup("get");
            IPutFile putFile_stub = (IPutFile) registry.lookup("put");

            String content = new String(getFile_stub.get(filename), StandardCharsets.UTF_8);
            System.out.println(content);
        }
        catch (Exception e) {
            System.err.println("Client exception: " + e.toString());
            e.printStackTrace();
        }
    }
}
