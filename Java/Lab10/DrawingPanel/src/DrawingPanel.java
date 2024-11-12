import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

public class DrawingPanel extends JFrame {
    private final JPanel colorPanel;
    private final JScrollPane scrollPanel;
    private final DrawArea drawArea;
    private Color currentColor = Color.GREEN;

    public DrawingPanel() {
        setTitle("Drawing Application");
        setBounds(200, 200, 800, 600);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        drawArea = new DrawArea();
        scrollPanel = new JScrollPane(drawArea);
        add(scrollPanel, BorderLayout.CENTER);

        colorPanel = new JPanel();
        add(colorPanel, BorderLayout.SOUTH);

        JButton blackButton = new JButton("Green");
        blackButton.addActionListener(e -> currentColor = Color.GREEN);
        JButton redButton = new JButton("Red");
        redButton.addActionListener(e -> currentColor = Color.RED);
        JButton blueButton = new JButton("Blue");
        blueButton.addActionListener(e -> currentColor = Color.BLUE);

        colorPanel.add(blackButton);
        colorPanel.add(redButton);
        colorPanel.add(blueButton);

        JMenuBar menuBar = new JMenuBar();
        JMenu fileMenu = new JMenu("File");
        JMenuItem saveItem = new JMenuItem("Save Image");
        saveItem.addActionListener(e -> saveImage());
        JMenuItem openItem = new JMenuItem("Open Image");
        openItem.addActionListener(e -> openImage());

        fileMenu.add(openItem);
        fileMenu.add(saveItem);
        menuBar.add(fileMenu);
        setJMenuBar(menuBar);

        setVisible(true);
    }

    private void saveImage() {
        JFileChooser fileChooser = new JFileChooser();
        int option = fileChooser.showSaveDialog(this);
        if (option == JFileChooser.APPROVE_OPTION) {
            File file = fileChooser.getSelectedFile();
            try {
                ImageIO.write(drawArea.getImage(), "png", file);
                JOptionPane.showMessageDialog(this, "Image was saved successfully!");
            } catch (IOException e) {
                JOptionPane.showMessageDialog(this, "Failed to save image!");
            }
        }
    }

    private void openImage() {
        JFileChooser fileChooser = new JFileChooser();
        int option = fileChooser.showOpenDialog(this);
        if (option == JFileChooser.APPROVE_OPTION) {
            File file = fileChooser.getSelectedFile();
            try {
                BufferedImage image = ImageIO.read(file);
                drawArea.setImage(image);
            } catch (IOException e) {
                JOptionPane.showMessageDialog(this, "Failed to open image!");
            }
        }
    }

    private class DrawArea extends JPanel {
        private BufferedImage image;
        private Graphics graphics;
        private int prevX, prevY;

        public DrawArea() {
            setPreferredSize(new Dimension(1000, 1000));
            image = new BufferedImage(1000, 1000, BufferedImage.TYPE_INT_RGB);
            graphics = image.createGraphics();
            Graphics2D graphics2D = (Graphics2D) graphics;
            graphics2D.setStroke(new BasicStroke(8));
            graphics.setColor(Color.WHITE);
            graphics.fillRect(0, 0, image.getWidth(), image.getHeight());
            graphics.setColor(currentColor);

            addMouseListener(new MouseAdapter() {
                @Override
                public void mousePressed(MouseEvent e) {
                    prevX = e.getX();
                    prevY = e.getY();
                }
            });

            addMouseMotionListener(new MouseAdapter() {
                @Override
                public void mouseDragged(MouseEvent e) {
                    int x = e.getX();
                    int y = e.getY();
                    graphics.setColor(currentColor);
                    graphics.drawLine(prevX, prevY, x, y);
                    prevX = x;
                    prevY = y;
                    repaint();
                }
            });
        }

        public BufferedImage getImage() {
            return image;
        }

        public void setImage(BufferedImage newImage) {
            image = newImage;
            graphics = image.createGraphics();
            graphics.setColor(currentColor);
            repaint();
        }

        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            g.drawImage(image, 0, 0, null);
        }
    }

}
