import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.Random;

public class ButtonFrame extends JFrame{
    private final JButton button;
    private final JPanel panel;
    private final JLabel label;
    private Point initialClick;

    public ButtonFrame(){
        //initialize key elements
        button = new JButton("Click me");
        button.setFocusPainted(false);
        button.setFocusable(true);
        button.requestFocusInWindow();
        panel = new JPanel();
        panel.setLayout(null);
        label = new JLabel();
        label.setFont(new Font("Serif", Font.BOLD, 24));
        label.setBorder(BorderFactory.createLineBorder(Color.BLACK, 2));
        label.setHorizontalAlignment(SwingConstants.CENTER);

        // set settings to window
        setLayout(new BorderLayout());
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setBounds(200, 200, 500, 500);

        add(panel, BorderLayout.CENTER);
        add(label, BorderLayout.SOUTH);
        setVisible(true);

        // place button on panel
        Random rand = new Random();
        int x = rand.nextInt(getWidth() - 90);
        int y = rand.nextInt(getHeight() - 90);
        button.setBounds(x, y, 90, 30);
        panel.add(button);
        panel.repaint();


        panel.addMouseMotionListener(new MouseAdapter() {
            @Override
            public void mouseMoved(MouseEvent e) {
                label.setText("Mouse Position: (" + e.getX() + ", " + e.getY() + ")");
            }
        });

        panel.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                button.setLocation(e.getX(), e.getY());
                panel.repaint();
            }
        });

        button.addMouseListener(new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e) {
                if (e.isControlDown()) {
                    initialClick = e.getPoint();
                }
            }
        });

        button.addMouseMotionListener(new MouseAdapter() {
            @Override
            public void mouseDragged(MouseEvent e) {
                if (e.isControlDown()) {
                    int xMoved = e.getX() - initialClick.x;
                    int yMoved = e.getY() - initialClick.y;

                    int newX = button.getX() + xMoved;
                    int newY = button.getY() + yMoved;
                    button.setLocation(newX, newY);
                    panel.repaint();
                }
                Point panelPoint = SwingUtilities.convertPoint(button, e.getPoint(), panel);
                label.setText("Mouse Position: (" + panelPoint.x + ", " + panelPoint.y + ")");
            }
        });

        button.addKeyListener(new KeyAdapter() {
            @Override
            public void keyTyped(KeyEvent e) {
                if (!Character.isISOControl(e.getKeyChar())) {
                    button.setText(button.getText() + e.getKeyChar());
                }
            }

            @Override
            public void keyPressed(KeyEvent e) {
                if (e.getKeyCode() == KeyEvent.VK_BACK_SPACE) {
                    String text = button.getText();
                    if (!text.isEmpty()) {
                        button.setText(text.substring(0, text.length() - 1));
                    }
                }
            }
        });

    }

}
