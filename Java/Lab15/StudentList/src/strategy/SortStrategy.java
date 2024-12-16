package strategy;

import collection.Student;

import java.util.ArrayList;


public interface SortStrategy {
    ArrayList<Student> sortList(ArrayList<Student> students);
}
