import javax.swing.*;
import javax.swing.border.Border;
import javax.swing.border.LineBorder;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.BufferedImage;

public class MyFrame extends JFrame {
    public MyFrame() {
        setTitle("RadioButtons with Icons");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 300);

        // Панель для RadioButtons
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(1, 3)); // Радиокнопки в один ряд

        // Создание группы кнопок
        ButtonGroup group = new ButtonGroup();

        // Инициализация иконок
        Icon defaultIcon = createIcon(Color.LIGHT_GRAY, "Default");
        Icon selectedIcon = createIcon(Color.GREEN, "Selected");
        Icon hoverIcon = createIcon(Color.ORANGE, "Hover");
        Icon pressedIcon = createIcon(Color.RED, "Pressed");

        // Создание RadioButtons
        for (int i = 1; i <= 3; i++) {
            JRadioButton radioButton = new JRadioButton("Option " + i);
            radioButton.setHorizontalAlignment(SwingConstants.CENTER);

            // Установка базовой иконки
            radioButton.setIcon(defaultIcon);

            // Установка иконки для выбранного состояния
            //radioButton.setSelectedIcon(selectedIcon);

            // Добавление обработчиков мыши
            radioButton.addMouseListener(new MouseAdapter() {
                @Override
                public void mouseEntered(MouseEvent e) {
                    if (!radioButton.isSelected()) {
                        radioButton.setIcon(hoverIcon);
                    }
                }

                @Override
                public void mouseExited(MouseEvent e) {
                    if (!radioButton.isSelected()) {
                        radioButton.setIcon(defaultIcon);
                    }
                }

                @Override
                public void mousePressed(MouseEvent e) {
                    radioButton.setIcon(selectedIcon);
                }

                @Override
                public void mouseReleased(MouseEvent e) {
                    if (!radioButton.isSelected()) {
                        radioButton.setIcon(pressedIcon);
                    }
                }
            });

            // Добавление кнопки в группу и панель
            group.add(radioButton);
            panel.add(radioButton);
        }

        add(panel, BorderLayout.CENTER);
        setVisible(true);
    }

    // Метод для создания иконок
    private Icon createIcon(Color color, String text) {
        int width = 100;
        int height = 50;
        Image image = new BufferedImage(width, height, BufferedImage.TYPE_INT_ARGB);
        Graphics2D g = (Graphics2D) image.getGraphics();
        g.setColor(color);
        g.fillRect(0, 0, width, height);
        g.setColor(Color.BLACK);
        g.drawRect(0, 0, width - 1, height - 1);
        g.setFont(new Font("Arial", Font.BOLD, 16));
        FontMetrics metrics = g.getFontMetrics();
        int x = (width - metrics.stringWidth(text)) / 2;
        int y = (height - metrics.getHeight()) / 2 + metrics.getAscent();
        g.drawString(text, x, y);
        g.dispose();
        return new ImageIcon(image);
    }

}
