package visitor;

public class CountElementsVisitor implements Visitor{
    private int count = 0;

    public int getCount(){
        return count;
    }

    @Override
    public void visit(int element) {
        ++count;
    }
}
