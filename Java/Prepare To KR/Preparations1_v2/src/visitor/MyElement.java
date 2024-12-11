package visitor;

public interface MyElement<T> {
    void accept(MyVisitor<T> visitor);
}
