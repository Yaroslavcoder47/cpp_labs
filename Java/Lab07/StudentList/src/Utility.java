import java.io.*;
import java.util.*;

public class Utility {
    private static final List<Student> studentList = new ArrayList<>();

    public static List<Student> getStudents(){
        return studentList;
    }

    public static void addStudent(Student newStudent){
        studentList.add(newStudent);
    }

    public static void checkFileOpen(String name) throws FileNotFoundException, IOException {
        File file = new File(name);

        if(!file.exists() || !file.isFile()){
            throw new FileNotFoundException("File does not exist!");
        }
        if(!file.canRead()){
            throw new IOException("File cannot be read!");
        }
    }

    public static void loadDataFromFile(String fileName) {
        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(" ");
                int id = Integer.parseInt(parts[0]);
                String surname = parts[1];
                int course = Integer.parseInt(parts[2]);
                int group = Integer.parseInt(parts[3]);
                studentList.add(new Student(id, surname, course, group));
            }
        } catch (IOException exc) {
            System.out.println(exc.getMessage());
        }
    }

    public static StringBuilder showSortedStudents() {
        StringBuilder result = new StringBuilder();
        Map<String, Integer> surnameCount = new HashMap<>();
        for (Student student : studentList) {
            surnameCount.put(student.getSurname(), surnameCount.getOrDefault(student.getSurname(), 0) + 1);
        }

        studentList.sort(
                Comparator.comparing(Student::getSurname)
                        .thenComparingInt(Student::getCourse)
                        .thenComparingInt(Student::getGroup)
                        .thenComparingInt(Student::getId)
        );

        for (Student student : studentList) {
            result.append(String.format("%d   %s   %d   %d\n", student.getId(), student.getSurname(), student.getCourse(), student.getGroup()));
        }
        return result;
    }
}
