public class NumberArray <T extends Number>{
    T[] array;

    T countSum() {
        Number sum = 0;
        for (T elem : array) {
            sum = sum.doubleValue() + ((Number)elem).doubleValue();
        }
        return (T)sum;
    }

    double findArithmeticMean() {
        if(array.length == 0){
            throw new IllegalArgumentException("Zero elements in array");
        }
        return (double)countSum() / array.length;
    }
}
