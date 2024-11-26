import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        List<Integer> list = new List<>(new ArrayList<>());
        list.addElement(1);
        list.addElement(2);
        list.addElement(3);
        ListIterator<Integer> iterator = (ListIterator<Integer>) list.CreateIterator();
        while (!iterator.IsDone()) {
            try {
                System.out.println(iterator.CurrentItem());
                iterator.Next();
            } catch (IteratorOutOfBounds exception) {
                System.err.println(exception);
            }
        }
    }
}