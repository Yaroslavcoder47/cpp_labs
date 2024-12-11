package view;

import collection.MyCollection;
import iterator.MyIterator;


import javax.swing.*;
import java.awt.*;

public class HistogramView extends JPanel implements MyView {
    private MyCollection data;
    private final int COEFFICIENT = 20;

    public HistogramView(MyCollection data) {
        this.data = data;
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        MyIterator<Integer> iterator = data.createIterator();
        int i = 0;
        for (iterator.first(); !iterator.isDone(); iterator.next(), ++i) {
            g.drawRect(0, i * COEFFICIENT, iterator.currentItem() * COEFFICIENT, COEFFICIENT);
        }
    }

    @Override
    public void update() {
        repaint();
    }
}
