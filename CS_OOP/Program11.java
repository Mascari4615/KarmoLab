import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Program11 extends JFrame {

    private ImageIcon icon;
    private Image img;

    private int imgSizePer = 100;
    private int imgOriginSize = 100;

    private boolean isDrawingCircle = false;
    private int colorCount = 1;
    private Color color = Color.black;
    private Point circlePos = new Point(0, 0);

    public Program11() {
        setTitle("Program11");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setContentPane(new MyPanel());
        CreateMenu();

        setSize(1000, 1000);
        setVisible(true);
    }

    class MyPanel extends JPanel {
        public void paintComponent(Graphics g) {
            super.paintComponent(g);

            if (img != null)
                g.drawImage(img, 0, 0, (int) (imgOriginSize * (1f + imgSizePer / 100f)),
                        (int) (imgOriginSize * (1f + imgSizePer / 100f)), this);
                        
            if (isDrawingCircle) {
                switch (colorCount) {
                    case 1:
                        g.setColor(color);
                        g.fillOval(circlePos.x, circlePos.y, 100, 100);
                        break;

                    case 3:
                        g.setColor(Color.RED);
                        g.fillArc(circlePos.x, circlePos.y, 100, 100, 0, 120);
                        g.setColor(Color.YELLOW);
                        g.fillArc(circlePos.x, circlePos.y, 100, 100, 120, 120);
                        g.setColor(Color.GREEN);
                        g.fillArc(circlePos.x, circlePos.y, 100, 100, 240, 120);
                        break;
                    case 4:
                        g.setColor(Color.RED);
                        g.fillArc(circlePos.x, circlePos.y, 100, 100, 0, 90);
                        g.setColor(Color.YELLOW);
                        g.fillArc(circlePos.x, circlePos.y, 100, 100, 90, 90);
                        g.setColor(Color.GREEN);
                        g.fillArc(circlePos.x, circlePos.y, 100, 100, 180, 90);
                        g.setColor(Color.BLUE);
                        g.fillArc(circlePos.x, circlePos.y, 100, 100, 270, 90);
                        break;
                }

            }

            MyMouseListener listener = new MyMouseListener();
            addMouseListener(listener);
            addMouseMotionListener(listener);
        }
    }

    private void CreateMenu() {
        JMenuBar mb = new JMenuBar();
        JMenu drawImage = new JMenu("이미지그리기");
        MenuActionListener listener = new MenuActionListener();

        JMenuItem imageLoading = new JMenuItem("이미지로딩");
        imageLoading.addActionListener(listener);
        drawImage.add(imageLoading);

        drawImage.addSeparator();

        JMenuItem imageZoomOut = new JMenuItem("이미지축소(-10%)");
        imageZoomOut.addActionListener(listener);
        drawImage.add(imageZoomOut);

        drawImage.addSeparator();

        JMenuItem imageZoomIn = new JMenuItem("이미지확대(+10%)");
        imageZoomIn.addActionListener(listener);
        drawImage.add(imageZoomIn);

        JMenu drawCircle = new JMenu("마우스로원그리기");
        JMenuItem draw = new JMenuItem("원그리기");
        draw.addActionListener(listener);
        drawCircle.add(draw);
        JMenu changeColor = new JMenu("색상변경");
        JMenuItem red = new JMenuItem("빨강");
        red.addActionListener(listener);
        changeColor.add(red);
        JMenuItem blue = new JMenuItem("파랑");
        blue.addActionListener(listener);
        changeColor.add(blue);
        JMenuItem yellow = new JMenuItem("노랑");
        yellow.addActionListener(listener);
        changeColor.add(yellow);
        drawCircle.add(changeColor);
        drawCircle.addSeparator();
        JMenuItem delete = new JMenuItem("지우기");
        delete.addActionListener(listener);
        drawCircle.add(delete);

        JMenu separateCircle = new JMenu("원분할하기");
        JMenuItem color3 = new JMenuItem("3색원");
        color3.addActionListener(listener);
        separateCircle.add(color3);
        separateCircle.addSeparator();
        JMenuItem color4 = new JMenuItem("4색원");
        color4.addActionListener(listener);
        separateCircle.add(color4);

        mb.add(drawImage);
        mb.add(drawCircle);
        mb.add(separateCircle);

        setJMenuBar(mb);
    }

    class MenuActionListener implements ActionListener {
        public void actionPerformed(java.awt.event.ActionEvent e) {
            String cmd = e.getActionCommand();
            switch (cmd) {
                case "이미지로딩":
                    icon = new ImageIcon("images/image0.png");
                    img = icon.getImage();
                    break;
                case "이미지축소(-10%)":
                    imgSizePer -= 10;
                    break;
                case "이미지확대(+10%)":
                    imgSizePer += 10;
                    break;
                case "원그리기":
                    isDrawingCircle = true;
                    break;
                case "빨강":
                    color = Color.RED;
                    break;
                case "파랑":
                    color = Color.BLUE;
                    break;
                case "노랑":
                    color = Color.YELLOW;
                    break;
                case "지우기":
                    isDrawingCircle = false;
                    break;
                case "3색원":
                    colorCount = 3;
                    break;
                case "4색원":
                    colorCount = 4;
                    break;
            }
            repaint();

        }
    }

    class MyMouseListener extends MouseAdapter {
        public void mousePressed(MouseEvent e) {
            circlePos = e.getPoint();
        }
    }

    public static void main(String args[]) {
        new Program11();
    }
}