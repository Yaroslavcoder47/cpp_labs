import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class MyFrame extends JFrame {
    private JPanel leftSide;
    private JPanel rightSide;
    private JList<String> list;
    private DefaultListModel<String> listModel;

    private KeyPressSubject keyObject = new KeyPressSubject();
    private LabelObserver labelObs = new LabelObserver();
    private ListObserver listObs = new ListObserver();


    public MyFrame() {
        setTitle("KeyBoard Listener");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(400, 400, 600, 300);
        setLayout(new BorderLayout());

        // build left side of frame
        leftSide = new JPanel(new BorderLayout());
        JLabel keyLabel = new JLabel("Press any key", SwingConstants.CENTER);
        keyLabel.setFont(new Font("Arial", Font.BOLD, 36));
        leftSide.add(keyLabel, BorderLayout.CENTER);

        labelObs.setLabel(keyLabel);
        keyObject.attach(labelObs);


        // build right side of panel
        rightSide = new JPanel(new BorderLayout());
        listModel = new DefaultListModel<>();
        list = new JList<>(listModel);
        list.setFocusable(false);
        JScrollPane scrollPane = new JScrollPane(list);
        rightSide.add(scrollPane, BorderLayout.CENTER);

        listObs.setList(listModel);
        keyObject.attach(listObs);


        // divide frame into two halves
        JSplitPane splitPane = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT, leftSide, rightSide);
        splitPane.setDividerLocation(0.5);
        splitPane.setResizeWeight(0.5);
        add(splitPane, BorderLayout.CENTER);


        addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                String keyText = KeyEvent.getKeyText(e.getKeyCode());
                keyObject.keyPressed(keyText);
            }
        });

        setFocusable(true);
        requestFocusInWindow();
        setVisible(true);
    }

}
