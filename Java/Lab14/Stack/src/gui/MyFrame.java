package gui;

import collection.StackCollection;

import javax.swing.*;
import java.awt.*;

public class MyFrame<T> extends JFrame {
    private StackCollection<T> stackCollection;
    private JList<T> list;
    public MyFrame(StackCollection<T> collection){
        stackCollection = collection;

        setTitle("collection.StackCollection Viewer");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(400, 400, 400, 300);


        DefaultListModel<T> listModel = new DefaultListModel<>();

        for (int i = 0; i < stackCollection.size(); i++) {
            listModel.addElement(stackCollection.getItemByIndex(i));
        }

        list = new JList<>(listModel);
        list.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        list.setFont(new Font("Arial", Font.PLAIN, 16));

        JScrollPane scrollPane = new JScrollPane(list);

        setLayout(new BorderLayout());
        add(scrollPane, BorderLayout.CENTER);

        setVisible(true);
    }
}
