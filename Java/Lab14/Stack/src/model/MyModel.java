package model;

import collection.StackCollection;
import observer.Observable;

public class MyModel implements Observable {
    private StackCollection myCollection;

    public MyModel(StackCollection myCollection) {
        this.myCollection = myCollection;
    }
}
