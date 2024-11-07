import java.awt.*;
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.List;

public class StartGUI extends JFrame{
    private List<Tree> trees;
    public StartGUI(){
        setTitle("New Year Present");
        setBounds(600, 300, 500, 250);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        JPanel mainPanel = new JPanel(new BorderLayout());

        JLabel fileNameLabel = new JLabel("File Path");
        fileNameLabel.setHorizontalAlignment(SwingConstants.CENTER);
        fileNameLabel.setBorder(BorderFactory.createEmptyBorder(40, 0, 0,0));

        JPanel inputPanel = new JPanel(new FlowLayout(FlowLayout.CENTER, 10, 20));
        JTextField inputField = new JTextField(20);
        JButton inputButton = new JButton("Enter");

        inputPanel.add(inputField);
        inputPanel.add(inputButton);

        mainPanel.add(fileNameLabel, BorderLayout.NORTH);
        mainPanel.add(inputPanel, BorderLayout.CENTER);

        add(mainPanel);

        inputButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e){
                try {
                    TreeUtill.readFromFile(trees, inputField.getText());
                    System.out.println(inputField.getText());
                    MyFrame frame = new MyFrame(trees);
                    dispose();
                } catch (FileNotFoundException ex) {
                    System.out.println(ex);
                }
            }
        });
        setVisible(true);
    }
}