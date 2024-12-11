package strategy;

import collection.MyCollection;
import visitor.CounterVisitor;

public class CountStrategy2 implements CountStrategy{
    @Override
    public int count(MyCollection collection) {
        CounterVisitor myVisitor;
        myVisitor = new CounterVisitor();
        collection.accept(myVisitor);
        return myVisitor.getCount();
    }
}
