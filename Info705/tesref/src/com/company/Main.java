package com.company;


public class Main {

    public static void main(String[] args) {
        A obj1 = new A();
        A obj2 = obj1;

        System.out.println("obj1 == obj2: " + (obj1 == obj2));
    }
}
