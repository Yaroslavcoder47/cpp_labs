package view;

import collection.StackCollection;
import iterator.Iterator;
import iterator.IteratorOutOfBounds;
import observer.Observer;

import javax.swing.*;
import java.awt.*;

public class HistogramView extends JPanel implements Observer {
    private StackCollection data;
    private final int COEFFICIENT = 20;

    public HistogramView(StackCollection data) {
        this.data = data;
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        Iterator<Integer> iterator = data.createIterator();
        int i = 0;
        for (iterator.first(); !iterator.isDone(); iterator.next(), ++i) {
            try {
                g.drawRect(0, i * COEFFICIENT, iterator.currentItem() * COEFFICIENT, COEFFICIENT);
            } catch (IteratorOutOfBounds e) {
                throw new RuntimeException(e);
            }
        }
    }

    @Override
    public void update() {
        repaint();
    }
}
