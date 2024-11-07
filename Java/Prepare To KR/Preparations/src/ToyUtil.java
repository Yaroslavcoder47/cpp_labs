import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;
import java.util.function.Predicate;

public class ToyUtil {
    public static void readFromFile(List<Toy> list, String fileName) throws FileNotFoundException {
        Scanner sc = new Scanner(new File(fileName));
        while(sc.hasNext()){
            list.add(Toy.parseToy(sc.nextLine()));
        }
        sc.close();
    }

    public static String writeToString(List<Toy> list){
        StringBuilder result = new StringBuilder();
        list.forEach(t -> result.append(t).append("\n"));
        return result.toString();
    }

    public static void writeToFile(List<Toy> list, String fileName) throws FileNotFoundException {
        PrintWriter printWriter = new PrintWriter(new File(fileName));
        printWriter.print(ToyUtil.writeToString(list));
        printWriter.close();
    }

    public static List<Toy> findMinMax(List<Toy> list) throws EmptyCollectionException {
        if(list.isEmpty()){
            throw new EmptyCollectionException("from findMinMax");
        }

        List<Toy> res = new ArrayList<>();
        res.add(list.stream().min(Comparator.comparing(Toy::getName)).get());
        res.add(list.stream().max(Comparator.comparing(Toy::getName)).get());
        return res;
    }

    public static List<Toy> findByPredicate(List<Toy> list, Predicate<Toy> predicate){
        return list.stream().filter(predicate).toList();
    }

    public static List<Toy> takeSortedList(List<Toy> list, Comparator<Toy> comp){
        return list.stream().sorted(comp).toList();
    }
}
