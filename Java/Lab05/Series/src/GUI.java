import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class GUI extends JFrame{
    public GUI(){
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(400, 200, 550, 340);

        JPanel mainPanel = new JPanel(new BorderLayout(10, 10));
        mainPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

        JPanel leftPanel = new JPanel();
        leftPanel.setLayout(new BoxLayout(leftPanel, BoxLayout.Y_AXIS));

        JTextArea textArea = new JTextArea(5, 20);
        textArea.setEditable(false);
        JScrollPane scrollPane = new JScrollPane(textArea);
        leftPanel.add(scrollPane);

        JPanel inputPanel = new JPanel();
        inputPanel.setLayout(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(5, 5, 5, 5);

        JTextField field1 = new JTextField(10);
        JTextField field2 = new JTextField(10);
        JTextField field3 = new JTextField(10);

        JButton button1 = new JButton("Calculate Aj");
        JButton button2 = new JButton("Sum of series");
        JButton button3 = new JButton("String of elements");

        gbc.gridx = 0;
        gbc.gridy = 0;
        inputPanel.add(new JLabel("j:"), gbc);
        gbc.gridx = 1;
        inputPanel.add(field1, gbc);
        gbc.gridx = 2;
        inputPanel.add(button1, gbc);

        gbc.gridx = 0;
        gbc.gridy = 1;
        inputPanel.add(new JLabel("N:"), gbc);
        gbc.gridx = 1;
        inputPanel.add(field2, gbc);
        gbc.gridx = 2;
        inputPanel.add(button2, gbc);

        gbc.gridx = 0;
        gbc.gridy = 2;
        inputPanel.add(new JLabel("N:"), gbc);
        gbc.gridx = 1;
        inputPanel.add(field3, gbc);
        gbc.gridx = 2;
        inputPanel.add(button3, gbc);

        leftPanel.add(inputPanel);

        JPanel rightPanel = new JPanel();
        rightPanel.setLayout(new BoxLayout(rightPanel, BoxLayout.Y_AXIS));

        String[] comboBoxData = {"Liner", "Exponential"};
        JComboBox<String> comboBox = new JComboBox<>(comboBoxData);
        comboBox.setPreferredSize(new Dimension(150, 25));
        comboBox.setMaximumSize(new Dimension(150, comboBox.getPreferredSize().height));
        rightPanel.add(comboBox);

        JTextField textField = new JTextField(15);
        textField.setMaximumSize(new Dimension(Integer.MAX_VALUE, textField.getPreferredSize().height));
        rightPanel.add(Box.createVerticalStrut(10));
        rightPanel.add(textField);

        JButton rightButton = new JButton("Save to file");
        rightPanel.add(Box.createVerticalStrut(10));
        rightPanel.add(rightButton);

        mainPanel.add(leftPanel, BorderLayout.WEST);
        mainPanel.add(rightPanel, BorderLayout.EAST);

        add(mainPanel);
        setVisible(true);

        button1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int num = Integer.parseInt(field1.getText());
                
            }
        });
    }
}
