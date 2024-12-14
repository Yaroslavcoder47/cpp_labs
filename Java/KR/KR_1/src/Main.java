import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<Tree> trees = new ArrayList<>();

        try {
            TreeUtill.readFromFile(trees, "input1.txt");
            System.out.println("Деревья из input1.txt:");
            trees.forEach(System.out::println);

            TreeUtill.readFromFile(trees, "input2.txt");
            System.out.println("\nДеревья из input2.txt:");
            trees.forEach(System.out::println);
        } catch (FileNotFoundException e) {
            System.out.println("Файл не найден: " + e.getMessage());
        }

        List<Tree> sortedByAge = TreeUtill.sortTreeByAge(trees);
        System.out.println("\nДеревья, отсортированные по возрасту и имени:");
        sortedByAge.forEach(System.out::println);

        long leafyCount = TreeUtill.countTreeByType(trees, TreeEnum.LEAFY);
        System.out.println("\nКоличество деревьев типа LEAFY: " + leafyCount);

        Tree searchTree = new ForestTree("Pine", 30, TreeEnum.PINY, 10);
        List<Tree> foundTrees = TreeUtill.findTreeInCollection(trees, searchTree);
        System.out.println("\nНайденные деревья с параметрами, как у " + searchTree + ":");
        foundTrees.forEach(System.out::println);

        List<Tree> sortedByEffectiveAge = TreeUtill.sortByEffectiveOnAge(trees);
        System.out.println("\nДеревья, отсортированные по эффективности на возраст:");
        sortedByEffectiveAge.forEach(System.out::println);

        List<String> treesStartingWithS = TreeUtill.findTreesStartWith(trees);
        System.out.println("\nИмена деревьев, начинающиеся с буквы 'S':");
        treesStartingWithS.forEach(System.out::println);
    }
}
