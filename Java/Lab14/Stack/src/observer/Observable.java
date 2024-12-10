package observer;

import java.util.ArrayList;

public interface Observable {
    ArrayList<Observer> observers = new ArrayList<>();
    default void addObserver(Observer observer) {
        observers.add(observer);
    }
    default void notifyObservers() {
        observers.forEach(Observer::update);
    }
}
