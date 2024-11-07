import java.util.Comparator;
import java.util.List;
import java.util.function.Predicate;

public class ProductUtil {
    public static int sumCount(List<Product> list){
        //list.stream().mapToInt(Product::getCount).sum();
        return list.stream().mapToInt(p->p.getCount()).sum();
    }

    public static int getMinimum(List<Product> list){
        return list.stream().mapToInt(Product::getCount).min().getAsInt();
    }

    public static List<Product> takeSortedList(List<Product> list){
        return list.stream().sorted(Comparator.comparing(Product::getCountry)
                .thenComparing(Product::getName).thenComparing(Product::getCount, Comparator.reverseOrder())).toList();
    }

    public static List<Product> takeSortedListByComparator(List<Product> list, Comparator<Product> comp){
        return list.stream().sorted(comp).toList();
    }

    public static List<Product> filterByPredicate(List<Product> list, Predicate<Product> predicate){
        return list.stream().filter(predicate).toList();
    }
}