import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Comparator;
import java.util.List;

public class MyFrame extends JFrame{
    private JTextArea text, text2;
    private List<Tree> trees;

    public MyFrame(List<Tree> trees) throws HeadlessException {
        this.trees = trees;
        setLayout(new GridLayout(1, 2));
        setVisible(true);

    }
}
