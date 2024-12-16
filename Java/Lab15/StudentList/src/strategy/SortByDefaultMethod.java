package strategy;

import collection.Student;

import java.util.ArrayList;
import java.util.Comparator;


public class SortByDefaultMethod implements SortStrategy {
    @Override
    public ArrayList<Student> sortList(ArrayList<Student> students) {
        System.out.println("Sort is set to default-method sort");
        students.sort(Comparator.comparing(Student::getSurname)
                .thenComparingInt(Student::getCourse)
                .thenComparingInt(Student::getGroup)
                .thenComparingInt(Student::getId));
        return students;
    }
}
