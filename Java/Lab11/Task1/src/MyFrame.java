import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class MyFrame extends JFrame {
    private JList<String> firstArray;
    private JList<String> secondArray;
    private JScrollPane firstScrollPane;
    private JScrollPane secondScrollPane;
    private ArrayList<String> firstArrayValues;
    private ArrayList<String> secondArrayValues;
    private JButton leftToRightButton;
    private JButton rightToLeftButton;
    private JPanel panel;

    public MyFrame(ArrayList<String> arr1, ArrayList<String> arr2) throws HeadlessException {
        setLayout(new BorderLayout());
        setBounds(200, 200, 400, 400);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        panel = new JPanel(new BorderLayout());

        firstArrayValues = arr1;
        secondArrayValues = arr2;
        firstArray = new JList<>(firstArrayValues.toArray(new String[0]));
        secondArray = new JList<>(secondArrayValues.toArray(new String[0]));
        firstScrollPane = new JScrollPane(firstArray);
        secondScrollPane = new JScrollPane(secondArray);
        firstScrollPane.setPreferredSize(new Dimension(165, getHeight()));
        secondScrollPane.setPreferredSize(new Dimension(165, getHeight()));

        leftToRightButton = new JButton(">");
        rightToLeftButton = new JButton("<");
        leftToRightButton.setPreferredSize(new Dimension(50, 30));
        rightToLeftButton.setPreferredSize(new Dimension(50, 30));



        add(firstScrollPane, BorderLayout.WEST);
        add(secondScrollPane, BorderLayout.EAST);
        panel.add(leftToRightButton, BorderLayout.NORTH);
        panel.add(rightToLeftButton, BorderLayout.SOUTH);
        add(panel, BorderLayout.CENTER);

        leftToRightButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                for(String value : firstArray.getSelectedValuesList()){
                    secondArrayValues.add(value);
                    firstArrayValues.remove(value);
                }
                firstArray.setListData(firstArrayValues.toArray(new String[0]));
                secondArray.setListData(secondArrayValues.toArray(new String[0]));
            }
        });

        rightToLeftButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                for(String value : secondArray.getSelectedValuesList()){
                    firstArrayValues.add(value);
                    secondArrayValues.remove(value);
                }
                firstArray.setListData(firstArrayValues.toArray(new String[0]));
                secondArray.setListData(secondArrayValues.toArray(new String[0]));
            }
        });
        setVisible(true);
    }
}
