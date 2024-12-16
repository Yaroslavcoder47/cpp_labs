package collection;

import org.xml.sax.SAXException;
import strategy.*;

import javax.xml.parsers.ParserConfigurationException;
import java.io.IOException;
import java.util.ArrayList;


public class StudentCollection {
    private ArrayList<Student> students = new ArrayList<Student>();
    private SortStrategy sortStrategy = new SortByDefaultMethod();
    private ReadStrategy readStrategy = new ReadWithSAX();

    public StudentCollection(ArrayList<Student> students) {
        this.students = students;
    }

    public void add(Student student){
        students.add(student);
    }

    public void setSortStrategy(SortStrategy strategy){
        this.sortStrategy = strategy;
    }

    public void setReadStrategy(ReadStrategy strategy){
        this.readStrategy = strategy;
    }

    public void sortStudents(){
        students = sortStrategy.sortList(students);
    }

    public void readData(String filepath) throws ParserConfigurationException, IOException, SAXException {
        students = readStrategy.readData(filepath);
    }

    @Override
    public String toString() {
        StringBuilder result = new StringBuilder();

        for (Student student : students) {
            result.append(student);
        }
        return result.toString();
    }
}
