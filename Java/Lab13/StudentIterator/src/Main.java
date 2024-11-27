
public class Main {
    public static void main(String[] args) {
        StudentLinkedList studentList = new StudentLinkedList();

        studentList.add(new Student("Олег"));
        studentList.add(new Student("Альберт"));
        studentList.add(new Student("Костя"));

        System.out.println("Студенты:");
        studentList.print();
        System.out.println();

        for(Student student : studentList){
            System.out.println(student);
        }
    }
}