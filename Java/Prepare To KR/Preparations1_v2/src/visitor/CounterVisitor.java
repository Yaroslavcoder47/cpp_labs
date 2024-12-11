package visitor;

public class CounterVisitor implements MyVisitor<Integer>{
    private int count = 0;

    public int getCount(){
        return count;
    }

    @Override
    public void visit(Integer element) {
        ++count;
    }
}
