package present;

import java.util.*;
import java.util.function.Predicate;

public class Present{
    private List<Candy> candies = new ArrayList<>();

    public Present(List<Candy> candies){
        this.candies = candies;
    }

    public void putCandy(Chocolate candy){
        candies.add(candy);
    }

    public void putCandy(Lollipop candy){
        candies.add(candy);
    }

    public List<Candy> getCandies(){
        return candies;
    }
    // flag means parameter of sorting, true - by weight, false - by sugar
    public List<Candy> sortCandies(Boolean flag){
        List<Candy> sortedCandies = candies;
        if(flag){
            sortedCandies.sort(Comparator.comparing(Candy::getWeight).thenComparing(Candy::getSugar));
        }
        else{
            sortedCandies.sort(Comparator.comparing(Candy::getSugar).thenComparing(Candy::getWeight));
        }
        return sortedCandies;
    }

    public int countWeight(){
        int resultWeight = 0;
        for(Candy item : candies){
            resultWeight += item.getWeight();
        }
        return resultWeight;
    }

    // find a candy which contains level of sugar within a given range
    public List<Candy> findCandyOfSugar(int minSugar, int maxSugar){
        List<Candy> resCandy = new ArrayList<>();
        for(Candy item : candies){
            if(item.getSugar() >= minSugar && item.getSugar() <= maxSugar){
                resCandy.add(item);
            }
        }
        return resCandy;
    }

    public String findCandy(Predicate<Candy> predicate) {
        List<Candy> foundCandies = candies.stream().filter(predicate).toList();
        StringBuilder result = new StringBuilder("Found Candies:\n");
        for (Candy candy : foundCandies) {
            result.append(candy.toString()).append("\n");
        }
        return result.toString();
    }

    public Map<Integer, List<Candy>> creatMapOfCandies(){
        Map<Integer, List<Candy>> candyMap = new HashMap<>();

        for(Candy candy : candies){
            int weight = candy.getWeight();
            candyMap.computeIfAbsent(weight, item -> new ArrayList<>()).add(candy);
        }
        return candyMap;
    }
}
