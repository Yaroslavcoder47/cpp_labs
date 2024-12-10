import collection.StackCollection;
import gui.MVCFrame;
import gui.MyFrame;
import iterator.IteratorOutOfBounds;
import iterator.StackIterator;
import model.MyModel;
import view.HistogramView;
import view.TextAreaView;
import visitor.CountElementsVisitor;
import visitor.MaxElementVisitor;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) throws InterruptedException {
        // test of logical part
        StackCollection<Integer> st = new StackCollection<>(new ArrayList<>());
        st.push(4);
        st.push(2);
        st.push(1);
        System.out.println(st.toString());

        // test of Visitor pattern
        MaxElementVisitor maxVisitor = new MaxElementVisitor();
        st.accept(maxVisitor);
        System.out.println("Max element: " + maxVisitor.getMaxElement());

        CountElementsVisitor countVisitor = new CountElementsVisitor();
        st.accept(countVisitor);
        System.out.println("Number of elements: " + countVisitor.getCount());

        StackCollection<Integer> st1 = new StackCollection<>(new ArrayList<>(List.of(4, 2, 1)));


        System.out.println("Is st equals to st1: " + st.equals(st1));
        System.out.println("Top element of st: " + st.top());
        StackIterator<Integer> iterator = (StackIterator<Integer>) st.createIterator();
        while (!iterator.isDone()) {
            try {
                System.out.println("Item: " +  iterator.currentItem());
                iterator.next();
            } catch (IteratorOutOfBounds exception) {
                System.err.println(exception);
            }
        }
        System.out.println("Pop st: " + st.pop());
        System.out.println(st.toString());
        st.pushAll(new ArrayList<>(List.of(3, 3, 3)));
        System.out.println(st.toString());


        System.out.println("Number of elements: " + countVisitor.getCount());


        // test of GUI
//        StackCollection<String> st2 = new StackCollection<>(new ArrayList<>(List.of("Alpha", "Beta", "Sun", "Moon",
//                "Light", "Shadow", "Ocean", "Wave", "Fire", "Ice", "Wind", "Storm", "Earth", "Sky", "Dream",
//                "Reality", "Time", "Space", "Sound", "Silence")));
//        MyFrame frame = new MyFrame<>(st2);

        //test of MVC
        MyModel model = new MyModel(st);
        TextAreaView view = new TextAreaView(st);
        model.addObserver(view);
        HistogramView histView = new HistogramView(st);
        model.addObserver(histView);
        model.notifyObservers();

        MVCFrame frame = new MVCFrame(view, histView);
        Thread.sleep(2000);
        st.pop();
        model.notifyObservers();
    }
}