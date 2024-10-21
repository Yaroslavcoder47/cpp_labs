import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Set<Student> students = new HashSet<>();
        students.add(new Student("IvanVanya", "vanya@mail.ru", "Ivan"));
        students.add(new Student("petka", "vanyaloh@mail.ru", "Petya"));
        students.add(new Student("LeraVleria", "lera@mail.ru", "Lera"));

        Course course = new Course("MA", students);
        System.out.println(course);

        for(Student elem : course){
            System.out.println(elem);
        }
        Iterator<Student> iter = course.iterator();
        while(iter.hasNext()){
            Student student = iter.next();
            System.out.println(student.getEmail());
        }
    }
}
