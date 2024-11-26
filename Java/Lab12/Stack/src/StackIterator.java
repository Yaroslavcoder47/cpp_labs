public class StackIterator<T> implements Iterator<T>{
    private int current;
    private StackCollection<T> stack;

    public StackIterator(StackCollection<T> stack){
        this.stack = stack;
        current = stack.size();
    }

    @Override
    public void first() {
        current = stack.size();
    }

    @Override
    public void next() {
        --current;
    }

    @Override
    public boolean isDone() {
        return current <= 0;
    }

    @Override
    public T currentItem() throws IteratorOutOfBounds {
        if(isDone()){
            throw new IteratorOutOfBounds("No elements!");
        }
        return stack.getItemByIndex(current-1);
    }
}
