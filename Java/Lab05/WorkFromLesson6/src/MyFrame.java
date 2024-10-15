import java.awt.*;
import javax.swing.*;

public class MyFrame extends JFrame {
    public MyFrame(String title) throws HeadlessException {
        super(title);

        setLayout(new GridLayout(1, 2));

        add(new StudentPanel(new Student(19, "Ivan")));
        add(new StudentPanel(new Student(18, "Peter")));
    }
}

