package gui;

import collection.Student;
import collection.StudentCollection;
import exception.MissingFieldException;
import org.xml.sax.SAXException;
import strategy.ReadWithDOM;
import strategy.ReadWithSAX;
import strategy.SortByDefaultMethod;
import strategy.SortByStreamApi;

import javax.swing.*;
import javax.xml.parsers.ParserConfigurationException;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.util.ArrayList;

public class StudentGUI extends JFrame {
    private JTextArea textArea;
    private final JTextField idField;
    private final JTextField nameField;
    private final JTextField courseField;
    private final JTextField groupField;
    private StudentCollection studentList = new StudentCollection(new ArrayList<>());

    public StudentGUI(String filepath, String readStrategy) throws ParserConfigurationException, IOException, SAXException {
        setTitle("Students Info");
        setBounds(600, 300, 600, 400);
        setDefaultCloseOperation(EXIT_ON_CLOSE);


        if(readStrategy.equals("SAX")){
            studentList.setReadStrategy(new ReadWithSAX());
        }
        else if(readStrategy.equals("DOM")){
            studentList.setReadStrategy(new ReadWithDOM());
        }


        studentList.readData(filepath);

        textArea = new JTextArea();
        textArea.setEditable(false);
        textArea.setText(studentList.toString());


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

        JButton addButton = new JButton("Add student");

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
                    textArea.setText(studentList.toString());

                }
                catch (MissingFieldException exc){
                    System.out.println(exc.getMessage());
                }

            }
        });

        dropdown.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String method = dropdown.getSelectedItem().toString();
                if(dropdown.getSelectedItem().equals("By StreamAPI")){
                    studentList.setSortStrategy(new SortByStreamApi());
                }
                else if(method.equals("Default methods")) {
                    studentList.setSortStrategy(new SortByDefaultMethod());
                }
                studentList.sortStudents();
                textArea.setText(studentList.toString());
            }
        });

        setVisible(true);
    }
}
