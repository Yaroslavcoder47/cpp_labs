package collection;

import iterator.MyIterable;
import iterator.MyIterator;
import strategy.MyStrategy;
import strategy.StreamStrategy;

import java.util.ArrayList;

public class MyCollection implements MyIterable<Integer> {
    private ArrayList<Integer> data = new ArrayList<>();
    private MyStrategy strategy = new StreamStrategy();

    public void add(Integer element) {
        data.add(element);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        MyIterator<Integer> iterator = this.createIterator();
        for (iterator.first(); !iterator.isDone(); iterator.next()) {
            sb.append(String.format("%5d", iterator.currentItem()));
        }
        return sb.toString();
    }

    public ArrayList<Integer> sort() {
        return strategy.sort(data);
    }

    public MyStrategy getStrategy() {
        return strategy;
    }

    public void setStrategy(MyStrategy strategy) {
        this.strategy = strategy;
    }

    @Override
    public MyIterator<Integer> createIterator() {
        return new MyIterator<>() {
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
            public Integer currentItem() {
                return data.get(current);
            }
        };
    }
}
