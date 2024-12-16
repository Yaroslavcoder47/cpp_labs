package strategy;

import collection.Student;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.stream.Collectors;


public class SortByStreamApi implements SortStrategy {
    @Override
    public ArrayList<Student> sortList(ArrayList<Student> students) {
        System.out.println("Sort is set to StreamAPI sort");
        return (ArrayList<Student>) students.stream().sorted(Comparator.comparing(Student::getSurname)
                .thenComparingInt(Student::getCourse)
                .thenComparingInt(Student::getGroup)
                .thenComparingInt(Student::getId)).collect(Collectors.toList());
    }
}
