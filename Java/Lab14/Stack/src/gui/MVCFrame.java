package gui;

import view.HistogramView;
import view.TextAreaView;

import javax.swing.*;
import java.awt.*;

public class MVCFrame extends JFrame {
    public MVCFrame(TextAreaView view, HistogramView histView){
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(300, 400);
        setLocationRelativeTo(null);

        setLayout(new GridLayout(1, 2));
        add(view);
        add(histView);
        setVisible(true);
    }
}
