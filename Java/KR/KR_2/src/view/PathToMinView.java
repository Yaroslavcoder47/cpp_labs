package view;

import collection.BinaryTree;

import javax.swing.*;

public class PathToMinView extends JTextArea implements MyView{
    private BinaryTree data;

    public PathToMinView(BinaryTree data) {
        this.data = data;
        update();
    }

    @Override
    public void update() {
        setText(data.moveToMin().toString());
    }
}
