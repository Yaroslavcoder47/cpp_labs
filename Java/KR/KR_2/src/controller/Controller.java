package controller;

import collection.BinaryTree;
import exception.NotNaturalNumber;
import model.MyModel;
import view.MyMinView;
import view.PathToMinView;
import view.TextAreaView;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Controller extends JFrame {
    private MyModel model;
    private TextAreaView view1;
    private MyMinView view2;
    private PathToMinView view3;

    public Controller(String title, MyModel model, TextAreaView view1, MyMinView view2, PathToMinView view3) {
        super(title);
        this.model = model;
        this.view1 = view1;
        this.view2 = view2;
        this.view3 = view3;

        setLayout(new GridLayout(1, 5));
        add(view1);


        JButton addButton = new JButton("Добавить");
        add(addButton);


        addButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String inputValue = JOptionPane.showInputDialog(null, "Введите значение:");
                if (inputValue != null && !inputValue.trim().isEmpty()) {
                    int value = Integer.parseInt(inputValue);
                    model.add(value);
                    view1.update();
                    view2.update();
                    view3.update();
                }
            }
        });

        add(view2);
        add(view3);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(800, 200);
        setLocationRelativeTo(null);
        setVisible(true);
    }
}
