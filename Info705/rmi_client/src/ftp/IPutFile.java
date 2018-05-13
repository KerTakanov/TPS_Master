package ftp;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface IPutFile extends Remote {
    public boolean put(String filename, byte[] content) throws RemoteException;
}
