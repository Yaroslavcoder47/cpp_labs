package strategy;

import java.util.ArrayList;
import java.util.stream.Collectors;

public class StreamStrategy implements MyStrategy {
    @Override
    public ArrayList<Integer> sort(ArrayList<Integer> unsorted) {
        return unsorted.stream().sorted().collect(Collectors.toCollection(ArrayList::new));
    }
}
