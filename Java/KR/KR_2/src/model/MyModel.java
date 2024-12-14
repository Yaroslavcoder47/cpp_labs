package model;

import collection.BinaryTree;
import exception.NotNaturalNumber;
import observer.MyObservable;

public class MyModel implements MyObservable {
    private BinaryTree myCollection;

    public MyModel(BinaryTree myCollection) {
        this.myCollection = myCollection;
    }

    public void add(int value) {
        try {
            myCollection.add(value);
        } catch (NotNaturalNumber e) {
            throw new RuntimeException(e);
        }
        notifyObservers();
    }
}