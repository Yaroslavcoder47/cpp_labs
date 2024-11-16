import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.ArrayList;

public class MyFrame extends JFrame {
    private ArrayList<JButton> buttons;
    private JPanel panel;

    public MyFrame(){
        panel = new JPanel();
        buttons = new ArrayList<>();
        for (int i = 0; i < 25; i++){
            buttons.add(new JButton(Integer.toString(i + 1)));
        }

        MouseListener listener = new MouseAdapter() {
            String previousText;
            @Override
            public void mouseEntered(MouseEvent e) {
                if(e.getSource() instanceof JButton){
                    JButton button = (JButton) e.getSource();
                    button.setBackground(Color.ORANGE);
                }
            }

            @Override
            public void mousePressed(MouseEvent e) {
                if(e.getSource() instanceof JButton){
                    JButton button = (JButton) e.getSource();
                    previousText = button.getText();
                    button.setText("Clicked!");
                }
            }

            @Override
            public void mouseReleased(MouseEvent e) {
                if(e.getSource() instanceof JButton){
                    JButton button = (JButton) e.getSource();
                    button.setText(previousText);
                }
            }

            @Override
            public void mouseExited(MouseEvent e) {
                if(e.getSource() instanceof JButton){
                    JButton button = (JButton) e.getSource();
                    button.setBackground(null);
                }
            }
        };

        setBounds(200, 200, 420, 420);
        panel.setLayout(new GridLayout(5, 5));
        for(int i = 0; i < 5; ++i){
            for(int j = 0; j < 5; ++j) {
                JButton button = buttons.get(i * 5 + j);
                button.addMouseListener(listener);
                panel.add(button);
            }
        }

        add(panel);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }
}
