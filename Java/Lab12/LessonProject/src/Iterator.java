public interface Iterator<T> {
    void First();
    void Next();
    boolean IsDone();
    T CurrentItem() throws IteratorOutOfBounds;
}
