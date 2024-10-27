package present;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;

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

    public List<Candy> sortCandies(){
        List<Candy> sortedCandies = candies;
        sortedCandies.sort(Comparator.comparing(Candy::getWeight).thenComparing(Candy::getSugar));
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
}
