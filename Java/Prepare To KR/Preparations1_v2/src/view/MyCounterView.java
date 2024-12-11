package view;

import collection.MyCollection;
import strategy.CountStrategy2;

import javax.swing.*;

public class MyCounterView extends JLabel implements MyView {
    private MyCollection collection;

    public MyCounterView(MyCollection collection) {
        this.collection = collection;
        update();
    }

    @Override
    public void update() {
        int n1 = collection.takeStrategyResult();
        collection.setStrategyCount(new CountStrategy2());
        int n2 = collection.takeStrategyResult();
        setText(String.format("Count strategy 1: %d Count strategy 2: %d", n1, n2));
    }
}
