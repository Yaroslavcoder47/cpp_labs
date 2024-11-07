public class FruitTree extends Tree{
    private int weightOfHarves;
    private int averageShelfLife; //in days
    private final int k = 5;

    public FruitTree(String name, int age, TreeEnum type, int weightOfHarves, int averageShelfLife){
        super(name, age, type);
        this.weightOfHarves = weightOfHarves;
        this.averageShelfLife = averageShelfLife;
    }

    @Override
    public int countEconomyEffective(){
        return getAge() * k * weightOfHarves / averageShelfLife;
    }
}
