import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class StudentPanel extends JPanel implements ActionListener{
    private Student student;
    private JTextField text;
    private JButton buttonChange;
    private JButton butOption;

    public StudentPanel(Student student) {
        this.student = student;

        setLayout(new GridLayout(2, 1));

        text = new JTextField(student.toString());
        text.setFont(new Font("Courier", Font.BOLD | Font.ITALIC, 24));
        add(text);

        buttonChange = new JButton("Change Student Age");
        add(buttonChange);
        buttonChange.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                student.setAge(student.getAge() + 1);
                text.setText(student.toString());
            }
        });
    }

    @Override
    public void actionPerformed(ActionEvent e){
        
    }
}