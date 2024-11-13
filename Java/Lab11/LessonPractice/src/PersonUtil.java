import java.util.Comparator;
import java.util.List;

public class PersonUtil {
    public static List<Person> takeSorted(List<Person> list) {
        return list.stream().sorted(Comparator.comparing(Person::getName, Comparator.reverseOrder())).toList();
    }
    public static List<Person> takeWithNameLength(List<Person> list){
        return list.stream().filter(p -> p.getName().length() == 3).toList();
    }
}
