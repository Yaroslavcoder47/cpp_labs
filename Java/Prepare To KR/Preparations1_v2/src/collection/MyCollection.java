package collection;

import iterator.MyIterable;
import iterator.MyIterator;
import strategy.CountStrategy;
import strategy.CountStrategy1;
import strategy.MyStrategy;
import strategy.StreamStrategy;
import visitor.MyElement;
import visitor.MyVisitor;

import java.util.ArrayList;

public class MyCollection implements MyIterable<Integer>, MyElement<Integer> {
    private ArrayList<Integer> data = new ArrayList<>();
    private MyStrategy strategy = new StreamStrategy();
    private CountStrategy strategyCount = new CountStrategy1();

    public void add(Integer element) {
        data.add(element);
    }

    public int size(){
        return data.size();
    }

    public int takeStrategyResult(){
        return strategyCount.count(this);
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

    public void setStrategySort(MyStrategy strategy) {
        this.strategy = strategy;
    }
    public void setStrategyCount(CountStrategy strategy)
    {
        this.strategyCount = strategy;
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

    @Override
    public void accept(MyVisitor<Integer> visitor) {
        MyIterator<Integer> iter = this.createIterator();
        for(iter.first(); !iter.isDone(); iter.next()){
            visitor.visit(iter.currentItem());
        }
    }
}
