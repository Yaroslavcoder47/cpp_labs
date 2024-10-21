import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.Iterator;

public class Writer {
    public void saveToFile(Course course, String filePath){
        try(BufferedWriter writer = new BufferedWriter(new FileWriter(filePath))){
            writer.write(course.getName());
            writer.newLine();
            Iterator<Student> iterator = course.iterator();
            while(iterator.hasNext()){
                writer.write(iterator.next().toString());
                writer.newLine();
            }
        }
        catch(IOException exc){
            System.err.println(exc.getMessage());
        }
    }
}
