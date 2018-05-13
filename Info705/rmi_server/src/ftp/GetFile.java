package ftp;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.rmi.RemoteException;

/**
 * Classe implémentant IGetFile permettant de récupérer le contenu d'un fichier selon son path
 */
public class GetFile implements IGetFile {
    /**
     * Retourne le contenu d'un fichier selon son path (filename) sous forme d'un tableau de byte.
     * @param filename Le chemin vers le fichier
     * @return Un tableau de byte représentant le contenu du fichier
     * @throws RemoteException
     */
    @Override
    public byte[] get(String filename) throws RemoteException {
        Path path = Paths.get(filename);
        System.out.println("Get \"" + filename + "\"");
        try {
            byte[] content = Files.readAllBytes(path);
            return content;
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }
}
