package strategy;

import collection.MyCollection;

public class CountStrategy1 implements CountStrategy{
    @Override
    public int count(MyCollection collection) {
        return collection.size();
    }
}
