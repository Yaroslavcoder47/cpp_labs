import javax.swing.*;
import java.awt.*;
import java.util.HashSet;
import java.util.Set;

public class Frame extends JFrame {

    public Frame(Course course) {
        setTitle("Course Information");
        setBounds(500, 350, 500, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        CoursePanel coursePanel = new CoursePanel(course);
        add(coursePanel);

        setVisible(true);
    }
}
