package present;

public class Lollipop extends Candy{
    private LollipopColor color;

    public Lollipop(int sugar, int weight, LollipopColor color){
        super(sugar, weight);
        this.color = color;
    }

    public void setColor(LollipopColor color){
        this.color = color;
    }

    public LollipopColor getColor(){
        return color;
    }

    @Override
    public String toString(){
        return getColor().toString() + " Lollipop" + super.toString();
    }
}
