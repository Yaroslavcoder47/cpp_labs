package observer;

import java.util.ArrayList;

public interface MyObservable {
    ArrayList<MyObserver> observers = new ArrayList<>();
    default void addObserver(MyObserver observer) {
        observers.add(observer);
    }
    default void notifyObservers() {
        observers.forEach(MyObserver::update);
    }
}
