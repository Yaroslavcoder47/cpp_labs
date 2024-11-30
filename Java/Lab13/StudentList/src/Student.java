public class Student {
    private final int id;
    private final String surname;
    private final int course;
    private final int group;

    public Student(int id, String surname, int course, int group) {
        this.id = id;
        this.surname = surname;
        this.course = course;
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
}
