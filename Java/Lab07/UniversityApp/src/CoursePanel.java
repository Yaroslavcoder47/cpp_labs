import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.util.Set;

public class CoursePanel extends JPanel {


    public CoursePanel(Course course) {

        setLayout(new BorderLayout());
        JLabel courseNameLabel = new JLabel("Course: " + course.getName(), SwingConstants.CENTER);
        courseNameLabel.setFont(new Font("Arial", Font.BOLD, 16));
        add(courseNameLabel, BorderLayout.NORTH);


        String[] columnNames = {"Name", "Login", "Email", "Supervisor/Tutor", "Type"};

        String[][] studentData = getStudentData(course.getStudents());

        DefaultTableModel tableModel = new DefaultTableModel(studentData, columnNames); // create tample of table
        JTable studentTable = new JTable(tableModel);
        studentTable.setFillsViewportHeight(true);
        studentTable.setRowHeight(30);
        studentTable.setGridColor(Color.BLACK);

        JScrollPane scrollPane = new JScrollPane(studentTable);
        add(scrollPane, BorderLayout.CENTER);
    }

    private String[][] getStudentData(Set<Student> students) {
        String[][] data = new String[students.size()][5];
        int row = 0;
        for (Student student : students) {
            data[row][0] = student.getName();
            data[row][1] = student.getLogin();
            data[row][2] = student.getEmail();
            data[row][3] = (student instanceof Postgraduate) ? ((Postgraduate) student).getSupervisor().getName() : ((Undergraduate) student).getTutor().getName();
            data[row][4] = (student instanceof Postgraduate) ? "Postgraduate" : "Undergraduate";
            row++;
        }
        return data;
    }
}
