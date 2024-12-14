package collection;

import exception.NotNaturalNumber;
import iterator.MyIterable;
import iterator.MyIterator;
import strategy.MinStrategy;
import strategy.MinStrategy1;
import visitor.MyElement;
import visitor.MyVisitor;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class BinaryTree implements MyIterable, MyElement {
    private ArrayList<Integer> data = new ArrayList<>();
    private MinStrategy strategy = new MinStrategy1();

    public BinaryTree() {
        data = new ArrayList<>();
        data.add(0);
    }

    public int size() {
        return data.size();
    }

    public void add(int value) throws NotNaturalNumber {
        if (value <= 0) {
            throw new NotNaturalNumber("Not valid value");
        }
        int index = 0;
        while (index < data.size()) {
            int current = data.get(index);
            if (current == 0) {
                data.set(index, value);
                return;
            }
            if (value < current) {
                index = 2 * index + 1;
            } else {
                index = 2 * index + 2;
            }
            while (index >= data.size()) {
                data.add(0);
            }
        }
    }

    public void preorderTraversal(int index) {
        if (index >= data.size() || data.get(index) == 0) {
            return;
        }
        System.out.print(data.get(index) + " ");
        preorderTraversal(2 * index + 1);
        preorderTraversal(2 * index + 2);
    }

    @Override
    public MyIterator createIterator() {
        return new MyIterator() {
            private int current = 0;

            @Override
            public void first() {
                current = 0;
            }

            @Override
            public void next() {
                ++current;
            }

            @Override
            public boolean isDone() {
                return current >= data.size();
            }

            @Override
            public int currentItem() {
                return data.get(current);
            }
        };
    }

    @Override
    public void accept(MyVisitor visitor) {
        MyIterator iter = this.createIterator();
        for(iter.first(); !iter.isDone(); iter.next()){
            visitor.visit(iter.currentItem());
        }
    }


    public void save() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("output_tree.txt"))) {
            for (int value : data) {
                writer.write(value + " ");
            }
            writer.newLine();
            System.out.println("BinaryTree was saved to file output_tree.txt");
        } catch (IOException e) {
            System.err.println(e.getMessage());
        }
    }

    public ArrayList<Integer> moveToMin() {
        int i = 0;
        ArrayList<Integer> pathToElement = new ArrayList<>();
        while (i < data.size()) {
            pathToElement.add(data.get(i));
            if (data.get(i) == min()) {
                break;
            }
            int leftChild = 2 * i + 1;
            int rightChild = 2 * i + 2;

            if (leftChild < data.size() && data.get(leftChild) != 0 && (rightChild >= data.size() || data.get(leftChild) < data.get(rightChild))) {
                i = leftChild;
            }
            else if (rightChild < data.size() && data.get(rightChild) != 0) {
                i = rightChild;
            }
            else {
                break;
            }
        }
        return pathToElement;
    }


    public int min(){
        return strategy.minimum(data);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        MyIterator iterator = this.createIterator();
        for (iterator.first(); !iterator.isDone(); iterator.next()) {
            sb.append(String.format("%5d", iterator.currentItem()));
        }
        return sb.toString();
    }


    public MinStrategy getStrategy() {
        return strategy;
    }

    public void setStrategyMin(MinStrategy strategy) {
        this.strategy = strategy;
    }



}
