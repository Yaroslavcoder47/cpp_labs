package view;

import collection.MyCollection;


import javax.swing.*;

public class TextAreaView extends JTextArea implements MyView {
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
