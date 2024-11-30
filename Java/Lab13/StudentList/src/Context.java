import java.util.Comparator;
import java.util.List;

public class Context {
    private SortStrategy strategy = new SortByDefaultMethod();

    public void setStrategy(SortStrategy strategy){
        this.strategy = strategy;
    }

    public List<Student> sortStudents(List<Student> students, Comparator<Student> comp){
        return strategy.sortList(students, comp);
    }
}
