import java.util.Comparator;
import java.util.List;

public interface SortStrategy {
    List<Student> sortList(List<Student> students, Comparator<Student> comparator);
}
