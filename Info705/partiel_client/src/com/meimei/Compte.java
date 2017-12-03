package com.meimei;

public class Compte {
    public Compte(String id) {
        this(id, 0);
    }

    public Compte(String id, int solde) {
        this.id = id;
        this.solde = solde;
    }

    public int AjouterSolde(int solde) {
        this.solde += solde;
        return this.solde;
    }

    public int RetirerSolde(int solde) {
        this.solde -= solde;
        return this.solde;
    }

    public void AfficherSolde() {
        System.out.println(this);
    }

    @Override
    public String toString() {
        return "Solde du compte `" + id + "`: " + solde;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public int getSolde() {
        return solde;
    }

    public void setSolde(int solde) {
        this.solde = solde;
    }

    private String id;
    private int solde;
}
