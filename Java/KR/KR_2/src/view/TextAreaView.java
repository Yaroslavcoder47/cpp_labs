package view;

import collection.BinaryTree;


import javax.swing.*;

public class TextAreaView extends JTextArea implements MyView {
    private BinaryTree data;

    public TextAreaView(BinaryTree data) {
        this.data = data;
        update();
    }

    @Override
    public void update() {
        setText(data.toString());
    }
}
