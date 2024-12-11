import collection.MyCollection;

import controller.Controller;
import strategy.CountStrategy2;
import view.HistogramView;
import view.MyCounterView;
import view.TextAreaView;
import visitor.CounterVisitor;
import visitor.MyVisitor;
import visitor.PrinterVisitor;

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


        System.out.println("___________________");
        PrinterVisitor myVisitor;
        myVisitor = new PrinterVisitor();
        collection.accept(myVisitor);

        System.out.println("\n___________________");
        CounterVisitor secondVisitor;
        secondVisitor = new CounterVisitor();
        collection.accept(secondVisitor);
        System.out.println("Number of elements: " + secondVisitor.getCount());

        System.out.println("\n----------------------\n");
        System.out.println("count strategy 1:");
        int n = collection.takeStrategyResult();
        System.out.println("n = " + n);

        collection.setStrategyCount(new CountStrategy2());
        System.out.println("count strategy 2:");
        n = collection.takeStrategyResult();
        System.out.println("n = " + n);
        System.out.println("\n---------------------");

        MyCollection model = new MyCollection();
        model.add(5);
        model.add(3);
        model.add(7);

        TextAreaView view = new TextAreaView(model);
        HistogramView histView = new HistogramView(model);
        MyCounterView counterView = new MyCounterView(model);

        Controller controller = new Controller("KR", model, view, counterView);
        controller.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        controller.setSize(600, 400);
        controller.setLocationRelativeTo(null);


    }
}