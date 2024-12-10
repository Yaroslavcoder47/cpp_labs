package iterator;

public interface MyIterable<T> {
    MyIterator<T> createIterator();
}
