import java.io.File;
import java.io.FileNotFoundException;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class TreeUtill {
    public static void readFromFile(List<Tree> list, String fileName) throws FileNotFoundException {
        Scanner sc = new Scanner(new File(fileName));
        while(sc.hasNext()){
            if(fileName.equals("input1.txt")){
                list.add(new ForestTree(sc.next(), sc.nextInt(), TreeEnum.valueOf(sc.next()), sc.nextInt()));
            } else if (fileName.equals("input2.txt")) {
                list.add(new FruitTree(sc.next(), sc.nextInt(), TreeEnum.valueOf(sc.next()), sc.nextInt(), sc.nextInt()));
            }
        }
        sc.close();
    }

    public static List<Tree> sortTreeByAge(List<Tree> list){
        return list.stream().
                sorted(Comparator.comparing(Tree::getAge, Comparator.reverseOrder()).thenComparing(Tree::getName)).toList();
    }

    public static long countTreeByType(List<Tree> list, TreeEnum type){
        return list.stream().filter(tree -> tree.getType() == type).count();
    }

    public static List<Tree> findTreeInCollection(List<Tree> list, Tree element){
        list.stream().
                sorted(Comparator.comparing(Tree::getAge, Comparator.reverseOrder())
                        .thenComparing(Tree::getName).thenComparing(Tree::getType));
        return list.stream().filter(tree -> tree.getName().equals(element.getName()))
                .filter(tree -> tree.getAge() == element.getAge())
                .filter(tree -> tree.getType() == element.getType()).toList();
    }

    public static List<Tree> sortByEffectiveOnAge(List<Tree> list){
        return list.stream().sorted(Comparator.comparing((Tree tree) -> tree.countEconomyEffective() / tree.getAge(),
                Comparator.reverseOrder())).toList();
    }

    public static List<String> findTreesStartWith(List<Tree> trees) {
        return trees.stream().map(Tree::getName).filter(name -> name.startsWith("S")).distinct()
                .sorted(Comparator.reverseOrder()).collect(Collectors.toList());
    }
}
