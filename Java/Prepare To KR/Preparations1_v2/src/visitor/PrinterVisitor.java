package visitor;

public class PrinterVisitor implements MyVisitor<Integer>{
    @Override
    public void visit(Integer element) {
        System.out.printf("%5d", element);
    }
}
