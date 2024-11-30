import java.util.Comparator;
import java.util.List;

public class SortByStreamApi implements SortStrategy{
    @Override
    public List<Student> sortList(List<Student> students, Comparator<Student> comparator) {
        System.out.println("Sort is done with StreamAPI");
        return students.stream().sorted(comparator).toList();
    }
}
