package view;

import collection.StackCollection;
import observer.Observer;

import javax.swing.*;

public class TextAreaView extends JTextArea implements Observer {
    private StackCollection data;

    public TextAreaView(StackCollection data) {
        this.data = data;
        update();
    }

    @Override
    public void update() {
        setText(data.toString());
    }
}
