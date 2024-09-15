import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        if(args.length != 1){
            throw new IllegalArgumentException("Wrong number of arguments!");
        }
        try{
            changeString(args[0]);
        }
        catch(IllegalArgumentException ex){
            System.out.println(ex.getMessage());
        }
    }

    public static void changeString(String text){
        StringTokenizer st = new StringTokenizer(text);
        StringBuffer newString = new StringBuffer();
        while (st.hasMoreTokens()) {
            StringBuffer obj = new StringBuffer(st.nextToken());
            try{
                double numberDouble = Double.parseDouble(obj.toString());
                int startIndex = 0;

                if(obj.charAt(startIndex) == '-'){
                    startIndex++;
                }
                int currentIndex = startIndex;
                while(obj.charAt(currentIndex) == '0'){
                    currentIndex++;
                }
                if(obj.charAt(currentIndex) == '.'){
                    currentIndex--;
                }
                obj.delete(startIndex, currentIndex);
                newString.append(obj).append(' ');
            }
            catch(NumberFormatException exc){
                newString.append(obj).append(' ');
            }
        }
        System.out.println(newString);
    }
}