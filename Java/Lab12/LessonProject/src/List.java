import java.util.ArrayList;


public class List<T> implements Aggregate<T> {
    private ArrayList<T> list;

    public List(ArrayList<T> list){
        this.list = list;
    }

    public void addElement(T element){
        list.add(element);
    };

    public int count(){
        return list.size();
    }

    public T get(int index){
        return list.get(index);
    }


    @Override
    public Iterator<T> CreateIterator() {
        return new ListIterator<T>(this);
    }

}
