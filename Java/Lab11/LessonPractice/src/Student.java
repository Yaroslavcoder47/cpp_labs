public class Student extends Person implements Comparable<Person>{
    enum Faculty{
        FPMI,
        MMF
    }

    private Faculty faculty;

    public Student(String name, Faculty faculty) {
        super(name);
        this.faculty = faculty;
    }

    public void setFaculty(Faculty faculty) {
        this.faculty = faculty;
    }

    public Faculty getFaculty() {
        return faculty;
    }

    @Override
    public String toString(){
        return "Student{" +
                "name=" + getName() +
                " faculty=" + faculty + "}\n";
    }

    @Override
    public int compareTo(Person o){
        if(super.compareTo(o) != 0){
            return super.compareTo(o);
        }
        Student s = (Student)o;
        return getFaculty().compareTo(s.getFaculty());
    }
}
