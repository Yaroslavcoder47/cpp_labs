import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        JFrame fr = new MyFrame("First Swing App");
        fr.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        fr.setBounds(300, 200, 1000, 800);
        fr.setVisible(true);
    }
}
