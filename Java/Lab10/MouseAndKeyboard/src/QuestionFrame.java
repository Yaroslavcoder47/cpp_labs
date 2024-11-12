import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Random;

public class QuestionFrame extends JFrame{
    private final JLabel label;
    private final JPanel panel;
    private final JButton buttonMessage;
    private final JButton buttonRun;

    public QuestionFrame(){
        label = new JLabel("Do you like Java?");
        label.setFont(new Font("Serif", Font.BOLD, 18));
        label.setHorizontalAlignment(SwingConstants.CENTER);
        panel = new JPanel();
        panel.setLayout(null);
        buttonMessage = new JButton("No");
        buttonMessage.setFocusPainted(false);
        buttonRun = new JButton("Yes");
        buttonRun.setFocusPainted(false);

        // set settings to window
        setLayout(new BorderLayout());
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setBounds(200, 200, 500, 500);

        add(panel, BorderLayout.CENTER);
        add(label, BorderLayout.NORTH);
        setVisible(true);

        // place two buttons on panel
        Random rand = new Random();
        int x1, y1, x2, y2;
        do {
            x1 = rand.nextInt(panel.getWidth() - 90);
            y1 = rand.nextInt(panel.getHeight() - 30);
            x2 = rand.nextInt(panel.getWidth() - 90);
            y2 = rand.nextInt(panel.getHeight() - 30);
        } while (buttonsIntersect(x1, y1, x2, y2));


        buttonMessage.setBounds(x1, y1, 90, 30);
        buttonRun.setBounds(x2, y2, 90, 30);
        panel.add(buttonMessage);
        panel.add(buttonRun);
        panel.repaint();


        buttonMessage.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                label.setText("It is so sad(");
            }
        });

        buttonRun.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseEntered(MouseEvent e) {
                moveButton(buttonRun);
            }
        });


    }

    // change the position of buttonRun
    private void moveButton(JButton button) {
        Random rand = new Random();
        int maxX = panel.getWidth() - button.getWidth();
        int maxY = panel.getHeight() - button.getHeight();
        int numberOfGenerations = 30;
        int currentGeneration = 0;
        int newX, newY;
        do{
            newX = rand.nextInt(maxX);
            newY = rand.nextInt(maxY);
            currentGeneration++;
        }while(buttonsIntersect(newX, newY, buttonMessage.getX(), buttonMessage.getY()) && currentGeneration < numberOfGenerations);

        button.setLocation(newX, newY);
    }

    // function to check intersection of buttons
    private boolean buttonsIntersect(int x1, int y1, int x2, int y2) {
        Rectangle rect1 = new Rectangle(x1, y1, 90, 30);
        Rectangle rect2 = new Rectangle(x2, y2, 90, 30);
        return rect1.intersects(rect2);
    }

}
