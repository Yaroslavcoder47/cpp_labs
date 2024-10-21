import java.util.HashSet;
import java.util.Set;
import java.util.function.Predicate;

public class ProgrammingTest {
    public static void main(String[] args){
        Set<Student> students = new HashSet<>();
        students.add(new Undergraduate("gg4", "vanya@mail.ru", "Ivan", new Academic("Paul Deitel")));
        students.add(new Undergraduate("pr3", "petya@mail.ru", "Petya", new Academic("Cay Hortsmann")));
        students.add(new Postgraduate("te2", "yarik@mail.ru", "Yaroslav", new Academic("Paul Deitel")));
        students.add(new Postgraduate("yj34", "vano@gmail.com", "Ivan", new Academic("Cay Horstmann")));
        students.add(new Postgraduate("jj8", "ilya@mail.ru", "Ilya", new Academic("Cay Horstmann")));

        Course course = new Course("MA", students);

        Frame frame = new Frame(course);

        Set<Postgraduate> res = course.getPostgraduate("Cay Horstmann");
        for(Postgraduate i : res){
            System.out.println(i.toString());
        }
        Notifier note = new Notifier(students);
        note.doNotifyAll("Hello, Students");

        Predicate<Student> nameStudent = student -> student.getName().equals("Ivan");
        Set<Student> filteredStudents = course.studentMatchPredicate(nameStudent);
        for(Student student : filteredStudents){
            System.out.println(student.toString());
        }

        Writer writeObj = new Writer();
        writeObj.saveToFile(course, "studentsInfo.txt");
    }
}
