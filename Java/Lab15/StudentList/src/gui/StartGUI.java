package gui;

import org.xml.sax.SAXException;

import javax.swing.*;
import javax.xml.parsers.ParserConfigurationException;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

public class StartGUI extends JFrame{
    private final JPanel mainPanel;
    private final JLabel fileNameLabel;
    private final JPanel inputPanel;
    private final JTextField inputField;
    private final JButton inputButton;
    private final JComboBox<String> methodComboBox;

    public StartGUI(){
        setTitle("Students Info");
        setBounds(600, 300, 500, 250);
        setDefaultCloseOperation(EXIT_ON_CLOSE);


        mainPanel = new JPanel(new BorderLayout());

        fileNameLabel = new JLabel("File Name");
        fileNameLabel.setHorizontalAlignment(SwingConstants.CENTER);
        fileNameLabel.setBorder(BorderFactory.createEmptyBorder(40, 0, 0,0));

        inputPanel = new JPanel(new FlowLayout(FlowLayout.CENTER, 10, 20));
        inputField = new JTextField(20);
        inputButton = new JButton("Enter");

        String[] methods = {"SAX", "DOM"};
        methodComboBox = new JComboBox<>(methods);
        methodComboBox.setSelectedIndex(0);

        inputPanel.add(inputField);
        inputPanel.add(methodComboBox);
        inputPanel.add(inputButton);

        mainPanel.add(fileNameLabel, BorderLayout.NORTH);
        mainPanel.add(inputPanel, BorderLayout.CENTER);

        add(mainPanel);

        inputButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e){
                String path = inputField.getText();
                String readStrategy = methodComboBox.getSelectedItem().toString();
                try {
                    StudentGUI studentWindow = new StudentGUI(path, readStrategy);
                } catch (ParserConfigurationException ex) {
                    throw new RuntimeException(ex);
                } catch (IOException ex) {
                    throw new RuntimeException(ex);
                } catch (SAXException ex) {
                    throw new RuntimeException(ex);
                }
                dispose();
            }
        });

        setVisible(true);
    }
}
