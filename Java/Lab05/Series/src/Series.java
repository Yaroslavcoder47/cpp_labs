import java.io.IOException;
import java.lang.StringBuilder;
import java.io.FileWriter;

public abstract class Series{
    public final int firstElement;

    public Series(int element){
        firstElement = element;
    }

    public abstract int calculateElement(int j);

    public int sumOfSeries(int n){
        int sum = firstElement;
        for(int i = 2; i <= n; ++i){
            sum += calculateElement(i);
        }
        return sum;
    }

    public String seriesToString(int n){
        StringBuilder res = new StringBuilder(Integer.toString(firstElement));
        for(int i = 2; i <= n; ++i){
            res.append(" ").append(Integer.toString(calculateElement(i)));
        }
        return res.toString();
    }

    public void saveToFile(String path, int n){
        try(FileWriter file = new FileWriter(path)){
            file.write("Elements of series\n");
            file.write(seriesToString(n) + "\n");
            file.write("Sum of elements\n");
            file.write(Integer.toString(sumOfSeries(n)));
        }
        catch (IOException exc){
            System.err.println(exc.getMessage());
        }
    }
}
