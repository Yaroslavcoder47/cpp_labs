package strategy;


import java.util.ArrayList;

public class MinStrategy2 implements MinStrategy {
    @Override
    public int minimum(ArrayList<Integer> collection) {
        int index = 0;
        while (index < collection.size() && collection.get(index) != 0) {
            int leftChildIndex = 2 * index + 1;
            if (leftChildIndex >= collection.size() || collection.get(leftChildIndex) == 0) {
                return collection.get(index);
            }
            index = leftChildIndex;
        }
        return 0;
    }
}
