package visitor;

public class MaxElementVisitor implements Visitor{
    private int maxElement = Integer.MIN_VALUE;

    public int getMaxElement(){
        return maxElement;
    }

    @Override
    public void visit(int element) {
        if(element > maxElement){
            maxElement = element;
        }
    }
}
