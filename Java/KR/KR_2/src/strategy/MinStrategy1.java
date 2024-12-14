package strategy;


import java.util.ArrayList;

public class MinStrategy1 implements MinStrategy {

    @Override
    public int minimum(ArrayList<Integer> collection) {
        return collection.stream().filter(i -> i != 0).min(Integer::compare)
                .orElseThrow(() -> new IllegalArgumentException("No such element"));
    }
}
