package ftp;

import java.rmi.Remote;
import java.rmi.RemoteException;

/**
 * Interface permettant de récupérer le contenu d'un fichier selon son chemin sous forme d'un tableau de byte
 */
public interface IGetFile extends Remote {
    /**
     * Retourne le contenu d'un fichier selon son path (filename) sous forme d'un tableau de byte.
     * @param filename Le chemin vers le fichier
     * @return Un tableau de byte représentant le contenu du fichier
     * @throws RemoteException
     */
    byte[] get(String filename) throws RemoteException;
}
