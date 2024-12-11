package controller;

import collection.MyCollection;
import view.MyCounterView;
import view.MyView;
import view.TextAreaView;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Controller extends JFrame {
    private MyCollection model;
    private TextAreaView view1;
    private MyCounterView view2;

    public Controller(String title, MyCollection model, TextAreaView view1, MyCounterView view2){
        super(title);
        this.model = model;
        this.view1 = view1;
        this.view2 = view2;

        setLayout(new GridLayout(1, 5));
        add(view1);

        JButton addButton = new JButton("add");
        add(addButton);

        addButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int value = 13;
                model.add(value);   //// usage of MVC
                view1.update();     //// usage of MVC
                view2.update();
            }
        });
        add(view2);

        setVisible(true);
    }
}
