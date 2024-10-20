public class NumberArray <T extends Number>{

    T countSum(T[] array) {
        Number sum = 0;
        for (T elem : array) {
            sum = sum.doubleValue() + ((Number)elem).doubleValue();
        }
        return (T)sum;
    }

    double findArithmeticMean(T[] array) {
        if(array.length == 0){
            throw new IllegalArgumentException("Zero elements in array");
        }
        return (double)countSum(array) / array.length;
    }
}
