import java.util.function.Predicate;

public class MyUtil {
    public static <T> int countIf(T[] arr, Predicate<T> pred){
        int count = 0;
        for(T element : arr){
            if(pred.test(element)){
                ++count;
            }
        }
        return count;
    }
}

class OddPredicate implements Predicate<Integer>{

    @Override
    public boolean test(Integer integer) {
        return integer%2==1;
    }
}

class DivPredicate implements Predicate<Integer>{
    private final int divider;

    public DivPredicate(int divider){
        this.divider = divider;
    }

    @Override
    public boolean test(Integer integer) {
        return integer%divider==1;
    }
}
