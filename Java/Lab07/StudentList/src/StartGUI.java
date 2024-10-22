import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;

public class StartGUI extends JFrame{
    public StartGUI(){
        setTitle("Student Info");
        setBounds(600, 300, 500, 250);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        JPanel mainPanel = new JPanel(new BorderLayout());

        JLabel fileNameLabel = new JLabel("File Name");
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
                String path = inputField.getText();
                try{
                    checkFileOpen(path);
                    StudentGUI studentWindow = new StudentGUI(path);
                    dispose();
                }
                catch (FileNotFoundException exc){
                    System.out.println(exc.getMessage());
                }
                catch (IOException exc){
                    System.out.println(exc.getMessage());
                }

            }
        });

        setVisible(true);
    }

    private void checkFileOpen(String name) throws FileNotFoundException, IOException{
        File file = new File(name);

        if(!file.exists() || !file.isFile()){
            throw new FileNotFoundException("File does not exist!");
        }
        if(!file.canRead()){
            throw new IOException("File cannot be read!");
        }
    }
}
