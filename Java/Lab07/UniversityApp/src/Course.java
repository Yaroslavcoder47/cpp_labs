import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;
import java.util.function.Predicate;

public class Course implements Iterable<Student>{
    private final String name;
    private final Set<Student> students;

    public Course(String name, Set<Student> students) {
        this.name = name;
        this.students = students;
    }

    public Set<Postgraduate> getPostgraduate(String NameOfSupervisor){
        Set<Postgraduate> result = new HashSet<>();
        for(Student student : students){
            if(student instanceof Postgraduate){
                if(((Postgraduate) student).getSupervisor().getName().equals(NameOfSupervisor)){
                    result.add((Postgraduate) student);
                }
            }
        }
        return result;
    }

    public void addStudent(Student student){
        students.add(student);
    }

    public Set<Student> getStudents(){
        return students;
    }

    public Set<Student> studentMatchPredicate(Predicate<Student> predicate){
        Set<Student> result = new HashSet<>();
        for(Student student : students){
            if(predicate.test(student)){
                result.add(student);
            }
        }
        return result;
    }

    public String getName(){
        return this.name;
    }

    @Override
    public String toString() {
        return "Course{" +
                "name='" + name + '\'' +
                ", students=" + students +
                '}';
    }

    @Override
    public Iterator<Student> iterator() {
        return students.iterator();
    }
}
