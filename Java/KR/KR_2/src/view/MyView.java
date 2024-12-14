package view;

import observer.MyObserver;

public interface MyView extends MyObserver {
    void update();
}
