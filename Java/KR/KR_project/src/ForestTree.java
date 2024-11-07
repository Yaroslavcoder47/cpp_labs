public class ForestTree extends Tree{
    private int countOfWood;
    private final int k = 2;
    public ForestTree(String name, int age, TreeEnum type, int countOfWood){
        super(name, age, type);
        this.countOfWood = countOfWood;
    }


    @Override
    public int countEconomyEffective(){
        return getAge() * k * countOfWood;
    }
}
