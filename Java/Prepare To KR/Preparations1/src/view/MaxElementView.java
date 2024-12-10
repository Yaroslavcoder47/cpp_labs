package view;

import collection.MyCollection;
import observer.MyObserver;
import visitor.MaxElementVisitor;

import javax.swing.*;

public class MaxElementView extends JTextArea implements MyObserver {
    private MyCollection data;
    private MaxElementVisitor visitor = new MaxElementVisitor();

    public MaxElementView(MyCollection data) {
        this.data = data;
    }

    @Override
    public void update() {
        data.accept(visitor);
        setText(Integer.toString(visitor.getMaxElement()));
    }
}
