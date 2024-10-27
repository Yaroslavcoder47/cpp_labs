package present;

public class Chocolate extends Candy{
    private ChocolateType type;

    public Chocolate(int sugar, int weight, ChocolateType type){
        super(sugar, weight);
        this.type = type;
    }

    public void setType(ChocolateType type){
        this.type = type;
    }

    public ChocolateType getType(){
        return type;
    }

    @Override
    public String toString(){
        return getType().toString() + " Chocolate" + super.toString();
    }
}
