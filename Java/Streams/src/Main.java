import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;
import java.util.function.Predicate;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        List<Product> products = new ArrayList<>();
        Scanner scan = new Scanner(new File("src/in.txt"));
        while(scan.hasNext()){
            Product pr = new Product(scan.next(), scan.next(), scan.nextInt());
            products.add(pr);
        }
        System.out.println(products);
        System.out.println("Sum = " + ProductUtil.sumCount(products));
        System.out.println("Min = " + ProductUtil.getMinimum(products));

        List<Product> sl = ProductUtil.takeSortedList(products);
        System.out.println(sl);

        Comparator<Product> comparator = Comparator.comparing(Product::getName);
        List<Product> sl1 = ProductUtil.takeSortedListByComparator(products, comparator);
        System.out.println(sl1);

        Predicate<Product> predicate = (Product p) -> {return p.getCount() >= 500;};
        List<Product> tmp = ProductUtil.filterByPredicate(products, predicate);
        System.out.println(tmp);

        String str = products.stream().map(Product::toString)
                .collect(Collectors.joining("\n"));
        System.out.println(str);

        Set<String> set = products.stream().map(Product::getName).collect(Collectors.toSet());
        System.out.println(set);

        Set<String> sset = new TreeSet<>(set);
        System.out.println(sset);

        List<String> ls = products.stream().map(Product::getName)
                .distinct().sorted().toList();
        System.out.println(ls);

        Map<String, List<Product>> map = products.stream().collect(Collectors.groupingBy(Product::getCountry));
        System.out.println(map);
    }
}