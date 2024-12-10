import collection.MyCollection;
import model.MyModel;
import view.HistogramView;
import view.TextAreaView;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        MyCollection collection = new MyCollection();
        collection.add(5);
        collection.add(3);
        collection.add(7);
        System.out.println(collection);

        ArrayList<Integer> list = collection.sort();
        System.out.println(list);

        MyModel model = new MyModel(collection);
        TextAreaView view = new TextAreaView(collection);
        model.addObserver(view);
        HistogramView histView = new HistogramView(collection);
        model.addObserver(histView);

        JFrame frame = new JFrame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 400);
        frame.setLocationRelativeTo(null);

        frame.setLayout(new GridLayout(1, 2));
        frame.add(view);
        frame.add(histView);

        collection.add(13);
        model.notifyObservers();

        frame.setVisible(true);
    }
}