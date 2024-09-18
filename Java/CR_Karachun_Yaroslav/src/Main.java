import javax.swing.plaf.synth.SynthTextAreaUI;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        System.out.println(task3(args));
    }

    public static void task1(String[] args){
        if(args.length != 2){
            throw new IllegalArgumentException("Wrong number of arguments!");
        }
        try{
            int a = Integer.parseInt(args[0]);
            int b = Integer.parseInt(args[1]);
            String strFirst = a + " + " + b + " = " + (a + b);
            String strSecond = a + " - " + b + " = " + (a - b);
            String strThird = a + " * " + b + " = " + (a * b);
            System.out.println(strFirst);
            System.out.println(strSecond);
            System.out.println(strThird);
        }
        catch(IllegalArgumentException ex){
            System.out.println(ex.getMessage());
        }
    }

    public static int task2(String[] args){
        int res = 0;
        if(args.length != 1){
            throw new IllegalArgumentException("Wrong number of arguments!");
        }
        String stroka = args[0];
        String[] words = stroka.split(" ");
        for(int i = 0 ; i < words.length; i++){
            if(words[i].matches("[a-zA-Z]+")){
                res++;
            }
        }
        return res;
    }

    public static String task3(String[] args){
        if(args.length != 1){
            throw new IllegalArgumentException("Wrong number of arguments!");
        }
        StringBuilder result = new StringBuilder();
        StringTokenizer currentStr = new StringTokenizer(args[0], ",. ");

        while(currentStr.hasMoreTokens()){
            String str = currentStr.nextToken();
            try{
                int num = Integer.parseInt(str);
            }
            catch (NumberFormatException ex){
                result.append(str).append(" ");
            }
        }
        return result.toString();
    }
}