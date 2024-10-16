import java.util.function.Predicate;

public class Array<T extends Comparable<T>> {
    T[] array;
    boolean contains(T value) {
        for (T elem : array) {
            if (elem.compareTo(value) == 0) {
                return true;
            }
        }
        return false;
    }

    int countElementsWithValue(T value) {
        int count = 0;
        for (T element : array) {
            if (element.equals(value)) {
                ++count;
            }
        }
        return count;
    }

    int countElementsGreaterThan(T value) {
        int count = 0;
        for (T element : array) {
            if (element.compareTo(value) > 0) {
                ++count;
            }
        }
        return count;
    }

    int countElementsMatchingPredicate(Predicate<T> predicate) {
        int count = 0;
        for (T element : array) {
            if (predicate.test(element)) {
                ++count;
            }
        }
        return count;
    }
}
