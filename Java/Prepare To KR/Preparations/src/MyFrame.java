import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Comparator;
import java.util.List;

public class MyFrame extends JFrame {
    private List<Toy> toys;
    private JTextArea text, text2;

    public MyFrame(List<Toy> toys) throws HeadlessException {
        this.toys = toys;

        setLayout(new GridLayout(1, 2));
        text = new JTextArea(ToyUtil.writeToString(toys));
        text.setBorder(BorderFactory.createLineBorder(Color.CYAN));

        Comparator<Toy> comp = Comparator.comparing(Toy::getName).thenComparing(Toy::getMinAge, Comparator.reverseOrder());
        text2 = new JTextArea(ToyUtil.writeToString(ToyUtil.takeSortedList(toys, comp)));
        text2.setBorder(BorderFactory.createLineBorder(Color.RED));


        add(text);
        add(text2);

        JButton btn1 = new JButton("Open data");
        btn1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                text2.setText("");
            }
        });

        add(btn1);
    }
}
