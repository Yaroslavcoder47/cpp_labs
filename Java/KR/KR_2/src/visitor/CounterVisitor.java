package visitor;

public class CounterVisitor implements MyVisitor{
    private int count = 0;

    public int getCount(){
        return count;
    }

    @Override
    public void visit(int element) {
        if(element != 0)
            count++;
    }
}
