import java.io.File;
import java.io.FileNotFoundException;
import java.util.Locale;
import java.util.Scanner;

public class ScanFile {
    public static void mainScan(){
        try(
                Scanner scan = new Scanner(new File("src/input.txt"))){
            scan.useLocale(Locale.US);
            scan.useDelimiter("[ ,;\t\n]+");
            double sum = 0.;
            while(scan.hasNext()){
                String item = scan.next();
                try {
                    int intValue = Integer.parseInt(item);
                    sum += intValue;
                } catch (NumberFormatException e) {
                    try {
                        double doubleValue = Double.parseDouble(item);
                        sum += doubleValue;
                    } catch (NumberFormatException ignored) {

                    }
                }
            }
            System.out.println(sum);
        }
        catch (
                FileNotFoundException e) {
            System.out.println(e.getMessage());
        }

    }

}
