import java.util.Arrays;

class MyUtil {
    public static <T> boolean find(T[] array, T value){
        for(T elem : array){
            if(elem.equals(value)){
                return true;
            }
        }
        return false;
    }

    public static <T> int count(T[] array, T value){
        int res = 0;
        for(T elem : array){
            if(elem.equals(value)){
                ++res;
            }
        }
        return res;
    }

    public static <T extends Comparable<T>> int countGreater(T[] array, T value){
        int res = 0;
        for(T elem : array){
            if(elem.compareTo(value) > 0){
                ++res;
            }
        }
        return res;
    }

    public static <T extends Number> int sum(T[] array, T value){
        int s = 0;
        for(T elem : array){
            s += elem.intValue();
        }
        return s;
    }
}

public class Main {
    public static void main(String[] args) {
        Integer[] array = {1, 12, 5};
        System.out.println("array = " + Arrays.toString(array));
        boolean count = MyUtil.find(array, 12);
        System.out.println("contain = " + count);

    }
}
