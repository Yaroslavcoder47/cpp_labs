abstract class Tree {
    private String name;
    private int age;
    private TreeEnum type;

    public Tree(String name, int age, TreeEnum type) {
        this.name = name;
        this.age = age;
        this.type = type;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public TreeEnum getType() {
        return type;
    }

    public int countEconomyEffective() {
        return 0;
    }

    @Override
    public String toString() {
        return "Tree{" +
                "name='" + name + '\'' +
                ", age=" + age +
                ", type=" + type +
                '}';
    }
}
