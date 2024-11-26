public class ListIterator<T> implements Iterator<T>{
    private List<T> list;
    private int current;

    public ListIterator(List<T> list){
        this.list = list;
    }

    @Override
    public void First() {
        current = 0;
    }

    @Override
    public void Next() {
        current++;
    }

    @Override
    public boolean IsDone() {
        return current >= list.count();
    }

    @Override
    public T CurrentItem() throws IteratorOutOfBounds {
        if(IsDone()){
            throw new IteratorOutOfBounds("No elements!");
        }
        return list.get(current);
    }
}
