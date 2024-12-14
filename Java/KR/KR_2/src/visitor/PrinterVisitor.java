package visitor;

import collection.BinaryTree;

public class PrinterVisitor implements MyVisitor{

    @Override
    public void visit(int element) {
        System.out.printf("%5d", element);
    }

}
