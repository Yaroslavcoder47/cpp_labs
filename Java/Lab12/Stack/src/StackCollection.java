import javax.swing.*;
import java.util.ArrayList;
import java.util.Collection;

public class StackCollection<T> implements Structure<T> {
    private ArrayList<T> stack;

    public StackCollection(ArrayList<T> stack){
        this.stack = stack;
    }

    public T top(){
        return stack.getLast();
    }

    public void push(T element){
        stack.add(element);
    }

    public T pop(){
        if(stack.isEmpty()){
            throw new IndexOutOfBoundsException("Stack is empty!");
        }
        T current = stack.getLast();
        stack.removeLast();
        return current;
    }

    public void pushAll(Collection<? extends T> elements){
        stack.addAll(elements);
    }

    public T getItemByIndex(int index){
        return stack.get(index);
    }

    @Override
    public Iterator<T> createIterator() {
        return new StackIterator<T>(this);
    }

    @Override
    public int size() {
        return stack.size();
    }

    @Override
    public boolean isEmpty() {
        return stack.isEmpty();
    }

    @Override
    public void clear() {
        stack.clear();
    }

    @Override
    public boolean equals(Object object) {
        if(! (object instanceof StackCollection<?>)) {return false;}
        return stack.equals(((StackCollection<?>) object).stack);
    }

    @Override
    public JList<T> getGUIStructure() {
        return new JList<T>((ListModel<T>) stack);
    }

    @Override
    public String toString(){
        return "Elements: " + stack.toString();
    }
}
