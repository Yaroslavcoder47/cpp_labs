package iterator;

import javax.swing.*;

public interface Structure<T> {
    Iterator<T> createIterator();

    boolean isEmpty();

    int size();

    void clear();

    boolean equals(Object object);

    String toString();

    JList<T> getGUIStructure();
}
