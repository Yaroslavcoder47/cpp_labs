public class Pupil extends Person implements Comparable<Person>{
    private int age;

    public void setAge(int age) {
        this.age = age;
    }

    public Pupil(String name, int age) {
        super(name);
        this.age = age;
    }

    public int getAge() {
        return age;
    }

    @Override
    public String toString(){
        return "Pupil{" +
                "name=" + getName() +
                " age=" + Integer.toString(age) + "}\n";
    }

    @Override
    public int compareTo(Person o){
        if(super.compareTo(o) != 0){
            return super.compareTo(o);
        }
        Pupil p = (Pupil)o;
        return age - p.age;
    }
}
