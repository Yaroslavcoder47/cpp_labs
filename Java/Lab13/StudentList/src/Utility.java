import java.io.*;
import java.util.*;

public class Utility {
    private static final Context context = new Context();


    public static StringBuilder showSortedStudents(List<Student> studentList) {
        StringBuilder result = new StringBuilder();
        studentList = sortOperation(studentList);

        for (Student student : studentList) {
            result.append(String.format("%d   %s   %d   %d\n", student.getId(), student.getSurname(), student.getCourse(), student.getGroup()));
        }
        return result;
    }

    public static List<Student> sortOperation(List<Student> studentList){
        return context.sortStudents(studentList, Comparator.comparing(Student::getSurname)
                        .thenComparingInt(Student::getCourse)
                        .thenComparingInt(Student::getGroup)
                        .thenComparingInt(Student::getId));
    }

    public static void setContextStrategy(String method){
        if(method.equals("By StreamAPI")){
            context.setStrategy(new SortByStreamApi());
        }
        else if(method.equals("Default methods")) {
            context.setStrategy(new SortByDefaultMethod());
        }
    }


    public static class ReadData{
        public static void checkFileOpen(String name) throws FileNotFoundException, IOException {
            File file = new File(name);

            if(!file.exists() || !file.isFile()){
                throw new FileNotFoundException("File does not exist!");
            }
            if(!file.canRead()){
                throw new IOException("File cannot be read!");
            }
        }

        public static void loadDataFromFile(List<Student> studentList, String fileName) {
            try (Scanner scanner = new Scanner(new FileReader(fileName))) {
                while (scanner.hasNext()) {
                    studentList.add(new Student(scanner.nextInt(), scanner.next(), scanner.nextInt(), scanner.nextInt()));
                }
            } catch (IOException exc) {
                System.out.println(exc.getMessage());
            }
        }
    }
}
