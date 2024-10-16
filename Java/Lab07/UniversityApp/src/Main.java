import java.util.HashSet;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Set<Student> students = new HashSet<>();
        students.add(new Student("IvanVanya", "vanya@mail.ru", "Ivan"));
        students.add(new Student("petka", "vanyaloh@mail.ru", "Petya"));
        students.add(new Student("LeraVleria", "lera@mail.ru", "Lera"));

        Course course = new Course("MA", students);
        System.out.println(course);
    }
}
