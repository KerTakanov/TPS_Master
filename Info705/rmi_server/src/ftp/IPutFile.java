package ftp;

import java.rmi.Remote;
import java.rmi.RemoteException;

/**
 * Interface permettant d'écrire un tableau de byte dans un fichier
 */
public interface IPutFile extends Remote {
    /**
     * Ecrit le contenu de `content` dans le fichier ayant pour chemin `filename`.
     * @param filename Le chemin vers le fichier
     * @param content Le contenu du fichier
     * @return true si l'opération a réussi, false sinon
     * @throws RemoteException
     */
    public boolean put(String filename, byte[] content) throws RemoteException;
}
