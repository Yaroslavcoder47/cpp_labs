import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

public class GUI extends JFrame{
    public GUI(){
        setTitle("Series");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(400, 200, 550, 340);

        JPanel mainPanel = new JPanel(new BorderLayout(10, 10));
        mainPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

        // left side of app
        JPanel leftPanel = new JPanel();
        leftPanel.setLayout(new BoxLayout(leftPanel, BoxLayout.Y_AXIS));

        // field with result text
        JTextArea textArea = new JTextArea(5, 20);
        textArea.setEditable(false);
        leftPanel.add(textArea);

        // part with input data
        JPanel inputPanel = new JPanel();
        inputPanel.setLayout(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(5, 5, 5, 5);

        JTextField calcElementField = new JTextField(10);
        JTextField calcSumField = new JTextField(10);
        JTextField printElementsField = new JTextField(10);

        JButton calcElementBtn = new JButton("Calculate Aj");
        JButton calcSumBtn = new JButton("Sum of series");
        JButton printElementsBtn = new JButton("String of elements");

        gbc.gridx = 0;
        gbc.gridy = 0;
        inputPanel.add(new JLabel("j:"), gbc);
        gbc.gridx = 1;
        inputPanel.add(calcElementField, gbc);
        gbc.gridx = 2;
        inputPanel.add(calcElementBtn, gbc);

        gbc.gridx = 0;
        gbc.gridy = 1;
        inputPanel.add(new JLabel("N:"), gbc);
        gbc.gridx = 1;
        inputPanel.add(calcSumField, gbc);
        gbc.gridx = 2;
        inputPanel.add(calcSumBtn, gbc);

        gbc.gridx = 0;
        gbc.gridy = 2;
        inputPanel.add(new JLabel("N:"), gbc);
        gbc.gridx = 1;
        inputPanel.add(printElementsField, gbc);
        gbc.gridx = 2;
        inputPanel.add(printElementsBtn, gbc);

        leftPanel.add(inputPanel);

        // right side of app
        JPanel rightPanel = new JPanel();
        rightPanel.setLayout(new BoxLayout(rightPanel, BoxLayout.Y_AXIS));

        // choose the series
        String[] comboBoxData = {"Liner", "Exponential"};
        JComboBox<String> comboBox = new JComboBox<>(comboBoxData);
        comboBox.setPreferredSize(new Dimension(150, 25));
        comboBox.setMaximumSize(new Dimension(150, comboBox.getPreferredSize().height));
        rightPanel.add(comboBox);

        // save to file part
        JTextField fileNameField = new JTextField(15);
        fileNameField.setMaximumSize(new Dimension(Integer.MAX_VALUE, fileNameField.getPreferredSize().height));

        rightPanel.add(Box.createVerticalStrut(10));
        rightPanel.add(fileNameField);

        JButton saveToFileBtn = new JButton("Save to file");
        rightPanel.add(Box.createVerticalStrut(10));
        rightPanel.add(saveToFileBtn);
        rightPanel.add(Box.createVerticalStrut(10));

        // set start settings of series
        JPanel fieldPanel = new JPanel(new GridBagLayout());
        GridBagConstraints fieldGbc = new GridBagConstraints();
        fieldGbc.fill = GridBagConstraints.HORIZONTAL;
        fieldGbc.insets = new Insets(5, 5, 5, 5);

        fieldGbc.gridx = 0;
        fieldGbc.gridy = 0;
        fieldPanel.add(new JLabel("First Element:"), fieldGbc);
        fieldGbc.gridx = 1;
        JTextField firstElementField = new JTextField(10);
        fieldPanel.add(firstElementField, fieldGbc);

        fieldGbc.gridx = 0;
        fieldGbc.gridy = 1;
        fieldPanel.add(new JLabel("Difference/Ratio:"), fieldGbc);
        fieldGbc.gridx = 1;
        JTextField differenceRatioField = new JTextField(10);
        fieldPanel.add(differenceRatioField, fieldGbc);

        rightPanel.add(Box.createVerticalStrut(10));

        rightPanel.add(fieldPanel);

        mainPanel.add(leftPanel, BorderLayout.WEST);
        mainPanel.add(rightPanel, BorderLayout.EAST);

        add(mainPanel);
        setVisible(true);

        // put mouse cursor into field of enter first element
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                firstElementField.requestFocusInWindow();
            }
        });

        calcElementBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) throws NumberFormatException{
                int num = Integer.parseInt(calcElementField.getText());
                int result = 0;
                if(comboBox.getSelectedItem() == "Liner"){
                    Liner linSeries = new Liner(Integer.parseInt(firstElementField.getText()), Integer.parseInt(differenceRatioField.getText()));
                    result = linSeries.calculateElement(num);
                }
                else if(comboBox.getSelectedItem() == "Exponential"){
                    Exponential expSeries = new Exponential(Integer.parseInt(firstElementField.getText()), Integer.parseInt(differenceRatioField.getText()));
                    result = expSeries.calculateElement(num);
                }
                textArea.setText(Integer.toString(result));
            }
        });

        calcSumBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int num = Integer.parseInt(calcSumField.getText());
                int result = 0;
                if(comboBox.getSelectedItem() == "Liner"){
                    Liner linSeries = new Liner(Integer.parseInt(firstElementField.getText()), Integer.parseInt(differenceRatioField.getText()));
                    result = linSeries.sumOfSeries(num);
                }
                else if(comboBox.getSelectedItem() == "Exponential"){
                    Exponential expSeries = new Exponential(Integer.parseInt(firstElementField.getText()), Integer.parseInt(differenceRatioField.getText()));
                    result = expSeries.sumOfSeries(num);
                }
                textArea.setText(Integer.toString(result));
            }
        });

        printElementsBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int num = Integer.parseInt(printElementsField.getText());
                String result = "";
                if(comboBox.getSelectedItem() == "Liner"){
                    Liner linSeries = new Liner(Integer.parseInt(firstElementField.getText()), Integer.parseInt(differenceRatioField.getText()));
                    result = linSeries.seriesToString(num);
                }
                else if(comboBox.getSelectedItem() == "Exponential"){
                    Exponential expSeries = new Exponential(Integer.parseInt(firstElementField.getText()), Integer.parseInt(differenceRatioField.getText()));
                    result = expSeries.seriesToString(num);
                }
                textArea.setText(result);
            }
        });

        saveToFileBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int num = Integer.parseInt(printElementsField.getText());
                String path = fileNameField.getText();
                try{
                    if(comboBox.getSelectedItem() == "Liner"){
                        Liner linSeries = new Liner(Integer.parseInt(firstElementField.getText()), Integer.parseInt(differenceRatioField.getText()));
                        linSeries.saveToFile(path, num);
                    }
                    else if(comboBox.getSelectedItem() == "Exponential") {
                        Exponential expSeries = new Exponential(Integer.parseInt(firstElementField.getText()), Integer.parseInt(differenceRatioField.getText()));
                        expSeries.saveToFile(path, num);
                    }
                }
                catch (IOException exc){
                    System.err.println("Error: " + exc.getMessage());
                }
            }
        });
    }
}
