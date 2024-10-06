public class Exponential extends Series{
    private final int q;
    public Exponential(int element, int q_par){
        super(element);
        q = q_par;
    }

    @Override
    public int calculateElement(int j){
        return (firstElement * (int) Math.pow(q, j - 1));
    }
}
