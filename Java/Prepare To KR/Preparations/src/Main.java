import javax.swing.*;
import java.io.FileNotFoundException;
import java.util.*;
import java.util.function.Predicate;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        List<Toy> toys = new ArrayList<>();
        ToyUtil.readFromFile(toys, "in.txt");
        System.out.println("Collection:\n" + ToyUtil.writeToString(toys));
        toys.add(new Toy("book", 16, 100));
        ToyUtil.writeToFile(toys, "out.txt");

        try {
            List<Toy> minMaxList = ToyUtil.findMinMax(toys);
            System.out.println(ToyUtil.writeToString(minMaxList));

        } catch (EmptyCollectionException e) {
            System.out.println(e);
        }

        Predicate<Toy> predicate1 = toy -> toy.getMinAge() >= 3 && toy.getName().equals("book");
        Predicate<Toy> predicate2 = toy -> toy.getName().startsWith("b");

        boolean flag = toys.stream().anyMatch(predicate2);
        System.out.println(flag);

        List<Toy> filteredList = ToyUtil.findByPredicate(toys, predicate1);
        System.out.println(ToyUtil.writeToString(filteredList));

        List<String> li = toys.stream().map(Toy::getName).distinct().sorted().toList();
        Set<String> set = toys.stream().map(Toy::getName).collect(Collectors.toCollection(TreeSet<String>::new));
        System.out.println(set);
        System.out.println(li);

        // by increasing names and decreasing minAge
        Comparator<Toy> comp = Comparator.comparing(Toy::getName).thenComparing(Toy::getMinAge, Comparator.reverseOrder());
        List<Toy> compList = ToyUtil.takeSortedList(toys, comp);
        System.out.println(ToyUtil.writeToString(compList));

        JFrame frame = new MyFrame(toys);
        frame.setBounds(100, 200, 800, 400);
        frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}