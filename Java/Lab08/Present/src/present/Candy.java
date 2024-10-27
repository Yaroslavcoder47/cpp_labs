package present;

public class Candy {
    private int sugar;  //grams of sugar in candy
    private int weight;

    public Candy(int sugar, int weight){
        this.sugar = sugar;
        this.weight = weight;
    }

    public void setSugar(int sugar){
        this.sugar = sugar;
    }

    public void setWeight(int weight){
        this.weight = weight;
    }

    public int getSugar(){
        return sugar;
    }

    public int getWeight(){
        return weight;
    }

    @Override
    public String toString(){
        return "{sugar: "  + Integer.toString(getSugar()) + ", weight: " + Integer.toString(getWeight()) + "}\n";
    }
}
