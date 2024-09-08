//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        if(args.length != 2){
            throw new IllegalArgumentException("Wrong number of arguments!");
        }
        double res_sum = calculateSum(args);
        System.out.println(res_sum);
    }

    public static double calculateSum(String[] args){
        double x = 1.5;
        double eps = 0.0001;
        try{
            x = Double.parseDouble(args[0]);
        }
        catch (NumberFormatException e){
            System.out.println("Invalid format for x argument: " + e.getMessage());
        }

        try{
            eps = Double.parseDouble(args[1]);
        }
        catch (NumberFormatException e){
            System.out.println("Invalid format for eps argument: " + e.getMessage());
        }

        double sum = 0;
        int factor = 2;
        for(int k = 1; ; k++){
            factor *= (k+2);
            double res = Math.pow(-1, k) * Math.pow(x, k + 2) / ((k + 1) * factor);
            if(Math.abs(res) >= eps){
                sum += res;
            }
            else {
                break;
            }
        }
        return sum;
    }
}