import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;

public class StudentGUI extends JFrame {
    private final JTextArea textArea;
    private final JTextField idField;
    private final JTextField nameField;
    private final JTextField courseField;
    private final JTextField groupField;
    private List<Student> studentList = new ArrayList<>();

    public StudentGUI(String filepath) {
        setTitle("Student Info");
        setBounds(600, 300, 600, 400);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);

        Utility.ReadData.loadDataFromFile(studentList, filepath);

        textArea = new JTextArea();
        textArea.setEditable(false);
        String textStudents = Utility.showSortedStudents(studentList).toString();
        textArea.setText(textStudents);

        JScrollPane scrollPane = new JScrollPane(textArea);
        add(scrollPane, BorderLayout.CENTER);
        scrollPane.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

        JPanel inputPanel = new JPanel();
        inputPanel.setLayout(new GridLayout(6, 2));
        inputPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

        JLabel idLabel = new JLabel("ID:");
        idField = new JTextField();

        JLabel nameLabel = new JLabel("Surname:");
        nameField = new JTextField();

        JLabel courseLabel = new JLabel("Course:");
        courseField = new JTextField();

        JLabel groupLabel = new JLabel("Group:");
        groupField = new JTextField();


        JLabel dropdownLabel = new JLabel("Select Sort Option:");
        String[] options = {"Default methods", "By StreamAPI"};
        JComboBox<String> dropdown = new JComboBox<>(options);

        JButton addButton = new JButton("Add Student");

        inputPanel.add(idLabel);
        inputPanel.add(idField);
        inputPanel.add(nameLabel);
        inputPanel.add(nameField);
        inputPanel.add(courseLabel);
        inputPanel.add(courseField);
        inputPanel.add(groupLabel);
        inputPanel.add(groupField);
        inputPanel.add(dropdownLabel);
        inputPanel.add(dropdown);
        inputPanel.add(new JLabel());
        inputPanel.add(addButton);

        add(inputPanel, BorderLayout.SOUTH);

        addButton.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    if(idField.getText().isEmpty() || nameField.getText().isEmpty() || courseField.getText().isEmpty()
                            || groupField.getText().isEmpty()){
                        throw new MissingFieldException("Some of the fields is empty!");
                    }
                    Student newStudent = new Student(
                            Integer.parseInt(idField.getText()),
                            nameField.getText(),
                            Integer.parseInt(courseField.getText()),
                            Integer.parseInt(groupField.getText())
                    );
                    studentList.add(newStudent);
                    textArea.setText(Utility.showSortedStudents(studentList).toString());
                }
                catch (MissingFieldException exc){
                    System.out.println(exc.getMessage());
                }



            }
        });

        dropdown.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Utility.setContextStrategy((String) dropdown.getSelectedItem());
            }
        });
    }
}
