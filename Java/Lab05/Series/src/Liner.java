public class Liner extends Series{
    private final int d;
    public Liner(int element, int d_par){
        super(element);
        d = d_par;
    }

    @Override
    public int calculateElement(int j){
        return (firstElement + d * (j - 1));
    }
}
