import collection.MyCollection;
import model.MyModel;
import view.HistogramView;
import view.MaxElementView;
import view.TextAreaView;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) throws InterruptedException {
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
        MaxElementView maxView = new MaxElementView(collection);
        model.addObserver(maxView);

        JFrame frame = new JFrame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(470, 400);
        frame.setLocationRelativeTo(null);

        frame.setLayout(new GridLayout(1, 2));
        frame.add(view);
        frame.add(histView);
        frame.add(maxView);
        frame.setVisible(true);

        model.notifyObservers();

        Thread.sleep(2000);

        collection.add(10);
        model.notifyObservers();


    }
}