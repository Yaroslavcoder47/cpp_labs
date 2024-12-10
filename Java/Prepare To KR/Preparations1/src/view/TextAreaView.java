package view;

import collection.MyCollection;
import observer.MyObserver;

import javax.swing.*;

public class TextAreaView extends JTextArea implements MyObserver {
    private MyCollection data;

    public TextAreaView(MyCollection data) {
        this.data = data;
        update();
    }

    @Override
    public void update() {
        setText(data.toString());
    }
}
