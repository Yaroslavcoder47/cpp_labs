import java.util.Comparator;
import java.util.List;

public class SortByDefaultMethod implements SortStrategy{
    @Override
    public List<Student> sortList(List<Student> students, Comparator<Student> comparator) {
        System.out.println("Sort is done with default-method sort");
        students.sort(comparator);
        return students;
    }
}
