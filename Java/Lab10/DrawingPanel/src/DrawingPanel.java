import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;
import java.awt.image.BufferedImage;
import java.util.ArrayList;
import java.util.List;
import java.awt.image.BufferedImage;

public class DrawingPanel extends JPanel implements MouseMotionListener {
    List<Point> curve = new ArrayList<>();
    BufferedImage bi = new BufferedImage(500, 500, BufferedImage.TYPE_INT_RGB);

    public DrawingPanel(){
        addMouseMotionListener(this);
    }

    @Override
    protected void paintComponent(Graphics g){
        super.paintComponent(g);
        g.drawOval(0, 0, this.getWidth(), this.getHeight());
//        for(Point pt: curve){
//            g.drawOval(pt.x, pt.y, 5, 5);
//        }
        g.drawImage(bi, 0, 100, null);
    }

    @Override
    public void mouseDragged(MouseEvent e) {
        curve.add(e.getPoint());
        //repaint();
        Graphics gr = bi.getGraphics();
        gr.drawOval(e.getX(), e.getY(), 10, 10);
        repaint();
    }

    @Override
    public void mouseMoved(MouseEvent e) {

    }
}
