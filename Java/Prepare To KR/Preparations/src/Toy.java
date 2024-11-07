import java.util.Scanner;

public class Toy {
    private String name;
    private int minAge;
    private int maxAge;

    public Toy(String name, int minAge, int maxAge) {
        this.minAge = minAge;
        this.name = name;
        this.maxAge = maxAge;
    }

    @Override
    public String toString() {
        return "Toy{" +
                "name='" + name + '\'' +
                ", minAge=" + minAge +
                ", maxAge=" + maxAge +
                '}';
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setMinAge(int minAge) {
        this.minAge = minAge;
    }

    public void setMaxAge(int mawAge) {
        this.maxAge = mawAge;
    }

    public String getName() {
        return name;
    }

    public int getMinAge() {
        return minAge;
    }

    public int getMaxAge() {
        return maxAge;
    }

    public static Toy parseToy(String str){
        Scanner sc = new Scanner(str);
        return new Toy(sc.next(), sc.nextInt(), sc.nextInt());
    }
}
