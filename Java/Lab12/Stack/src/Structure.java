import javax.swing.*;
import java.util.Collection;

public interface Structure<T> {
    Iterator<T> createIterator();

    int size();

    boolean isEmpty();

    void clear();

    boolean equals(Object object);

    String toString();

    JList<T> getGUIStructure();
}
