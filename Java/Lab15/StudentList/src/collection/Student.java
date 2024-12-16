package collection;

public class Student {
    private int id;
    private String surname;
    private int course;
    private int group;

    public Student(){};

    public Student(int id, String surname, int course, int group) {
        this.id = id;
        this.surname = surname;
        this.course = course;
        this.group = group;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public void setCourse(int course) {
        this.course = course;
    }

    public void setGroup(int group) {
        this.group = group;
    }

    public int getId(){
        return id;
    }

    public String getSurname(){
        return surname;
    }

    public int getCourse(){
        return course;
    }

    public int getGroup(){
        return group;
    }

    @Override
    public String toString() {
        return String.format("Student{%d   %s   %d   %d}\n", id, surname, course, group);
    }
}
