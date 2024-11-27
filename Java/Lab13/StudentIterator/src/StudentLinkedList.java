import java.util.Iterator;
import java.util.Arrays;

public class StudentLinkedList implements StudentList, Iterable<Student>{

    private Student data;
    private StudentNode head;

    private class StudentNode{
        Student data;
        StudentNode next;

        StudentNode(Student data) {
            this.data = data;
            this.next = null;
        }
    }

    private class SortedByNameIterator implements Iterator<Student> {

        private Student[] sortedList;
        private int index = 0;

        public SortedByNameIterator(StudentNode iter){
            int size = size(head);
            sortedList = new Student[size];
            int i = 0;
            while (head != null) {
                sortedList[i++] = head.data;
                head = head.next;
            }
            Arrays.sort(sortedList, (student1, student2) -> student1.name.compareToIgnoreCase(student2.name));
        }

        private int size(StudentNode node) {
            int count = 0;
            while (node != null) {
                ++count;
                node = node.next;
            }
            return count;
        }

        @Override
        public boolean hasNext() {
            return index < sortedList.length;
        }

        @Override
        public Student next() {
            return sortedList[index++];
        }
    }

    @Override
    public void add(Student student) {
        StudentNode newNode = new StudentNode(student);
        newNode.next = head;
        head = newNode;
    }

    @Override
    public void print() {
        StudentNode current = head;
        while (current != null) {
            System.out.print(current.data + "; ");
            current = current.next;
        }
    }

    @Override
    public Iterator<Student> iterator() {
        return new SortedByNameIterator(head);
    }
}
