import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.util.*;
import java.util.List;

public class StudentGUI extends JFrame {
    private final JTextArea textArea;
    private final JTextField idField;
    private final JTextField nameField;
    private final JTextField courseField;
    private final JTextField groupField;
    private final List<Student> studentList = new ArrayList<>();

    public StudentGUI(String filepath){
        setTitle("Student Info");
        setBounds(600, 300, 600, 400);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);

        loadDataFromFile(filepath);

        textArea = new JTextArea();
        textArea.setEditable(false);
        showSortedStudents();
        JScrollPane scrollPane = new JScrollPane(textArea);
        add(scrollPane, BorderLayout.CENTER);
        scrollPane.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

        JPanel inputPanel = new JPanel();
        inputPanel.setLayout(new GridLayout(5, 2));
        inputPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

        JLabel idLabel = new JLabel("ID:");
        idField = new JTextField();

        JLabel nameLabel = new JLabel("Surname:");
        nameField = new JTextField();

        JLabel courseLabel = new JLabel("Course:");
        courseField = new JTextField();

        JLabel groupLabel = new JLabel("Group:");
        groupField = new JTextField();

        JButton addButton = new JButton("Add Student");

        inputPanel.add(idLabel);
        inputPanel.add(idField);
        inputPanel.add(nameLabel);
        inputPanel.add(nameField);
        inputPanel.add(courseLabel);
        inputPanel.add(courseField);
        inputPanel.add(groupLabel);
        inputPanel.add(groupField);
        inputPanel.add(new JLabel());
        inputPanel.add(addButton);

        add(inputPanel, BorderLayout.SOUTH);

        addButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Student newStudent = new Student(Integer.parseInt(idField.getText()), nameField.getText(), Integer.parseInt(courseField.getText()),
                        Integer.parseInt(groupField.getText()));
                studentList.add(newStudent);
                showSortedStudents();
            }
        });
    }

    private void loadDataFromFile(String fileName) {
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

    private void showSortedStudents() {
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

        textArea.setText("");
        for (Student student : studentList) {
            textArea.append(String.format("%d   %s   %d   %d\n", student.getId(), student.getSurname(), student.getCourse(), student.getGroup()));
        }
    }
}
