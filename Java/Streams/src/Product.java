public class Product{
    private String name;
    private String country;
    private int count;

    public Product(String name, String country, int count){
        this.name = name;
        this.country = country;
        this.count = count;
    }

    public void setCount(int count) {
        this.count = count;
    }

    public void setCountry(String country) {
        this.country = country;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getCount() {
        return count;
    }

    public String getCountry() {
        return country;
    }

    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return "Product{" +
                "name='" + name + '\'' +
                ", country='" + country + '\'' +
                ", count=" + count +
                '}' + "\n";
    }

}
