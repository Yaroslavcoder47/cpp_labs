import javax.swing.*;
import java.awt.*;

public class MyFrame extends JFrame {
    private ButtonGroup groupOfButtons;
    private final ImageIcon[] images = new ImageIcon[]{
            new ImageIcon("images/notSelected.png"),
            new ImageIcon("images/selected.png"),
            new ImageIcon("images/pressed.png"),
            new ImageIcon("images/rollover.png")
    };


    public MyFrame(){
        setLayout(new GridLayout(2,2));
        groupOfButtons = new ButtonGroup();

        for (int i = 0; i < images.length; ++i) {
            Image image = images[i].getImage();
            Image scaledInstance = image.getScaledInstance(150, 150, java.awt.Image.SCALE_SMOOTH);
            images[i] = new ImageIcon(scaledInstance);
        }

        for (int i = 0; i < 4; ++i) {
            JRadioButton radioButton = new JRadioButton(images[0]);
            radioButton.setText("Button " + (i + 1));
            radioButton.setSelectedIcon(images[1]);
            radioButton.setPressedIcon(images[2]);
            radioButton.setRolloverIcon(images[3]);
            radioButton.setFont(new Font("Arial", Font.PLAIN, 24));
            groupOfButtons.add(radioButton);
            add(radioButton);
        }


        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setBounds(300, 200, 600, 500);
        setVisible(true);
    }

}
