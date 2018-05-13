package ftp;

import java.io.FileOutputStream;
import java.io.IOException;

/**
 * Classe implémentant IPutFile permettant d'écrire le contenu d'un tableau de byte dans un fichier selon son chemin
 */
public class PutFile implements IPutFile {
    /**
     * Ecrit le contenu d'un tableau de byte dans un fichier selon son chemin `filename`
     * @param filename Le chemin vers le fichier
     * @param content Le contenu du fichier
     * @return true si l'opération a réussi, false sinon
     */
    @Override
    public boolean put(String filename, byte[] content) {
        System.out.println("Put \"" + filename + "\"");
        try (FileOutputStream stream = new FileOutputStream(filename)) {
            stream.write(content);
        } catch (IOException e) {
            e.printStackTrace();
            return false;
        }

        return true;
    }
}
