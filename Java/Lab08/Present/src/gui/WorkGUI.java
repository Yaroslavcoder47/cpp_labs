package gui;
import io.Writer;
import present.Present;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class WorkGUI extends JFrame{
    private final JTextArea textArea;
    private final JTextField idField;
    private final JTextField nameField;
    private final JTextField courseField;
    private final JTextField groupField;
    private final Present present;

    public WorkGUI(Present present){
        this.present = present;
        setTitle("Student Info");
        setBounds(600, 300, 600, 400);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);


        textArea = new JTextArea();
        textArea.setEditable(false);

        textArea.setText(Writer.writeToString(this.present.getCandies()).toString());

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

            }
        });
    }
}
