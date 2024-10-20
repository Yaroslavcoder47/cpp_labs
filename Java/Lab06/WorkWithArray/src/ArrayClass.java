import java.util.function.Predicate;

public class ArrayClass<T extends Comparable<T>> {
    boolean contains(T[] array, T value) {
        for (T elem : array) {
            if (elem.compareTo(value) == 0) {
                return true;
            }
        }
        return false;
    }

    int countElementsWithValue(T[] array, T value) {
        int count = 0;
        for (T element : array) {
            if (element.equals(value)) {
                ++count;
            }
        }
        return count;
    }

    int countElementsGreaterThan(T[] array, T value) {
        int count = 0;
        for (T element : array) {
            if (element.compareTo(value) > 0) {
                ++count;
            }
        }
        return count;
    }

    int countElementsMatchingPredicate(T[] array, Predicate<T> predicate) {
        int count = 0;
        for (T element : array) {
            if (predicate.test(element)) {
                ++count;
            }
        }
        return count;
    }
}
