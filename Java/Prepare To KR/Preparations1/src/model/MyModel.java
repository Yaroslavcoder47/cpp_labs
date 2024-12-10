package model;

import collection.MyCollection;
import observer.MyObservable;

public class MyModel implements MyObservable {
    private MyCollection myCollection;

    public MyModel(MyCollection myCollection) {
        this.myCollection = myCollection;
    }
}
