import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<Person> list;

        list = new ArrayList<>();
        list.add(new Pupil("Ivan", 12));
        list.add(new Pupil("Ann", 11));
        list.add(new Pupil("Petr", 13));
        list.add(new Student("Anton", Student.Faculty.FPMI));
        list.add(new Student("Bim", Student.Faculty.MMF));
        list.add(new Student("Petr", Student.Faculty.FPMI));
        list.add(new Student("Yaroslav", Student.Faculty.MMF));
        System.out.println("List of people\n" + list + "\n");

        System.out.println("Sorted\n" + PersonUtil.takeSorted(list) + "\n");

        System.out.println("People with name length equals 3\n" + PersonUtil.takeWithNameLength(list));
    }
}