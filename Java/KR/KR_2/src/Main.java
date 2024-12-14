import collection.BinaryTree;
import controller.Controller;
import exception.NotNaturalNumber;
import model.MyModel;

import view.MyMinView;
import view.PathToMinView;
import view.TextAreaView;
import visitor.CounterVisitor;
import visitor.PrinterVisitor;


public class Main {
    public static void main(String[] args) {
        BinaryTree collection = new BinaryTree();
        try {
            collection.add(10);
            collection.add(5);
            collection.add(7);
        } catch (NotNaturalNumber e) {
            throw new RuntimeException(e);
        }

        System.out.println(collection);

        MyModel model = new MyModel(collection);
        TextAreaView view1 = new TextAreaView(collection);
        model.addObserver(view1);
        MyMinView view2 = new MyMinView(collection);
        model.addObserver(view2);
        PathToMinView view3 = new PathToMinView(collection);
        model.addObserver(view3);


        Controller controller = new Controller("Binary Tree", model, view1, view2, view3);


        model.notifyObservers();


        System.out.println("___________________");
        CounterVisitor firstVisitor;
        firstVisitor = new CounterVisitor();
        collection.accept(firstVisitor);
        System.out.println("Number of elements: " + firstVisitor.getCount());


        System.out.println("\n___________________");
        PrinterVisitor secondVisitor;
        secondVisitor = new PrinterVisitor();
        collection.accept(secondVisitor);

    }
}