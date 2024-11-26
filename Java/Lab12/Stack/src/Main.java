import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        // test of logical part
        StackCollection<Integer> st = new StackCollection<>(new ArrayList<>());
        st.push(4);
        st.push(2);
        st.push(1);
        System.out.println(st.toString());

        StackCollection<Integer> st1 = new StackCollection<>(new ArrayList<>(List.of(4, 2, 1)));

        System.out.println(st.size());
        System.out.println(st.equals(st1));
        System.out.println(st.top());
        StackIterator<Integer> iterator = (StackIterator<Integer>) st.createIterator();
        while (!iterator.isDone()) {
            try {
                System.out.println(iterator.currentItem());
                iterator.next();
            } catch (IteratorOutOfBounds exception) {
                System.err.println(exception);
            }
        }
        System.out.println(st.pop());
        System.out.println(st.size());
        System.out.println(st.toString());
        st.pushAll(new ArrayList<>(List.of(3, 3, 3)));
        System.out.println(st.toString());

        // test of GUI
        StackCollection<String> st2 = new StackCollection<>(new ArrayList<>(List.of("Alpha", "Beta", "Sun", "Moon",
                "Light", "Shadow", "Ocean", "Wave", "Fire", "Ice", "Wind", "Storm", "Earth", "Sky", "Dream",
                "Reality", "Time", "Space", "Sound", "Silence")));
        MyFrame frame = new MyFrame<>(st2);
    }
}