package strategy;

import java.util.ArrayList;
import java.util.Comparator;

public class NoStreamStrategy implements MyStrategy {
    @Override
    public ArrayList<Integer> sort(ArrayList<Integer> unsorted) {
        ArrayList<Integer> sorted = new ArrayList<>(unsorted);
        sorted.sort(Comparator.naturalOrder());
        return sorted;
    }
}
