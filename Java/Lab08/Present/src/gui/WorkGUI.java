package gui;
import io.Writer;
import present.*;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Map;
import java.util.function.Predicate;
import java.util.List;

public class WorkGUI extends JFrame{
    private final JTextArea textArea;
    private final JTextField typeField;
    private final JTextField sugarField;
    private final JTextField weightField;
    private final Present present;

    public WorkGUI(Present present){
        this.present = present;
        setTitle("Student Info");
        setBounds(600, 300, 800, 400);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);


        textArea = new JTextArea();
        textArea.setEditable(false);

        textArea.setText(Writer.writeToString(this.present.getCandies()).toString());

        JScrollPane scrollPane = new JScrollPane(textArea);
        add(scrollPane, BorderLayout.CENTER);
        scrollPane.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

        // left input panel
        JPanel leftInputPanel = new JPanel();
        leftInputPanel.setLayout(new GridLayout(5, 2, 10, 5));
        JLabel typeLabel = new JLabel("Type");
        JLabel typeOfCandyLabel = new JLabel("Color/Taste");

        JComboBox<String> candyBox = new JComboBox<>(new String[]{"Chocolate", "Lollipop"});
        typeField = new JTextField();

        JLabel sugarLabel = new JLabel("Sugar");
        sugarField = new JTextField();

        JLabel weightLabel = new JLabel("Weight");
        weightField = new JTextField();

        JButton addButton = new JButton("Add Candy");
        JButton writeToFileButton = new JButton("Write to file");
        leftInputPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));


        leftInputPanel.add(typeLabel);
        leftInputPanel.add(typeOfCandyLabel);
        leftInputPanel.add(candyBox);
        leftInputPanel.add(typeField);
        leftInputPanel.add(sugarLabel);
        leftInputPanel.add(sugarField);
        leftInputPanel.add(weightLabel);
        leftInputPanel.add(weightField);
        leftInputPanel.add(addButton);
        leftInputPanel.add(writeToFileButton);

        // Right sort panel
        JPanel sortRightPanel = new JPanel(new GridLayout(7, 1, 5, 5));
        sortRightPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

        JLabel sortLabel = new JLabel("Sort");
        JComboBox<String> sortBox = new JComboBox<>(new String[]{"By Weight", "By Sugar"});
        JButton sortButton = new JButton("Sort");
        JButton findButton = new JButton("Find");
        JLabel label1 = new JLabel("Summary weight and percent");
        JButton writeSumButton = new JButton("Result to file");
        JLabel mapLabel = new JLabel("Make map<weight, candies>");
        JButton mapButton = new JButton("Create Map");

        sortRightPanel.add(sortLabel);
        sortRightPanel.add(sortBox);
        sortRightPanel.add(sortButton);
        sortRightPanel.add(findButton);

        JPanel labelsPanel = new JPanel(new FlowLayout(FlowLayout.LEFT, 5, 0));
        labelsPanel.add(label1);
        labelsPanel.add(writeSumButton);
        sortRightPanel.add(labelsPanel);
        sortRightPanel.add(mapLabel);
        sortRightPanel.add(mapButton);

        // Bottom panel combining leftInputPanel and sortRightPanel
        JPanel bottomPanel = new JPanel(new BorderLayout());
        bottomPanel.add(leftInputPanel, BorderLayout.CENTER);
        bottomPanel.add(sortRightPanel, BorderLayout.EAST);

        add(bottomPanel, BorderLayout.SOUTH);

        addButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(candyBox.getSelectedItem().equals("Chocolate")){
                    present.putCandy(new Chocolate(Integer.parseInt(sugarField.getText()),
                            Integer.parseInt(weightField.getText()), ChocolateType.valueOf(typeField.getText())));
                }
                else if(candyBox.getSelectedItem().equals("Lollipop")){
                    present.putCandy(new Lollipop(Integer.parseInt(sugarField.getText()),
                            Integer.parseInt(weightField.getText()), LollipopColor.valueOf(typeField.getText())));
                }
                textArea.setText(Writer.writeToString(present.getCandies()).toString());
            }
        });

        writeToFileButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Writer.writeToFile("./data/candiesData.txt", present.getCandies());
                JOptionPane.showMessageDialog(WorkGUI.this, "Data was saved!");
            }
        });

        sortButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(sortBox.getSelectedItem().equals("By Weight")){
                    present.sortCandies(true);
                }
                else if(sortBox.getSelectedItem().equals("By Sugar")){
                    present.sortCandies(false);
                }
                textArea.setText(Writer.writeToString(present.getCandies()).toString());
            }
        });

        findButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int sugarValue = sugarField.getText().isEmpty() ? 1 : Integer.parseInt(sugarField.getText());
                int weightValue = weightField.getText().isEmpty() ? 1 : Integer.parseInt(weightField.getText());

                Predicate<Candy> predicate = candy -> {
                    boolean matchesSugar = sugarValue == -1 || candy.getSugar() == sugarValue;
                    boolean matchesWeight = weightValue == -1 || candy.getWeight() == weightValue;

                    return matchesWeight || matchesSugar;
                };

                String resultCandies = present.findCandy(predicate);
                textArea.setText(resultCandies);
            }
        });

        writeSumButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Writer.WriteToFileSum(present.getCandies());
                JOptionPane.showMessageDialog(WorkGUI.this, "Data was saved!");
            }
        });

        mapButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Map<Integer, List<Candy>> result = present.creatMapOfCandies();
                Writer.writeMapToFile(result);
                JOptionPane.showMessageDialog(WorkGUI.this, "Map<Weight, Candy> was saved!");
            }
        });
    }
}
