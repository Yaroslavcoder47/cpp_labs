package view;

import collection.BinaryTree;
import strategy.MinStrategy2;

import javax.swing.*;

public class MyMinView extends JLabel implements MyView {
    private BinaryTree collection;

    public MyMinView(BinaryTree collection) {
        this.collection = collection;
        update();
    }

    @Override
    public void update() {
        int n1 = collection.min();
        collection.setStrategyMin(new MinStrategy2());
        int n2 = collection.min();
        setText(String.format("MinStrategy1: %d MinStrategy2: %d", n1, n2));
    }
}
