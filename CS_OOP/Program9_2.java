import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Program9_2 extends JFrame
{
	private JLabel[] label = new JLabel[12];
	
	public Program9_2()
	{
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		
		c.setLayout(new GridLayout(4, 3));
		
		for(int i = 0; i < label.length; i ++)
		{
			label[i] = new JLabel(Integer.toString(i));
			label[i].setOpaque(true);
			label[i].setBackground(Color.white);
			c.add(label[i]);
			
			label[i].addMouseListener(new MouseAdapter()
					{
						public void mousePressed(MouseEvent e)
						{
							JLabel label = (JLabel)e.getSource();
							int r = (int)(Math.random() * 256);
							int g = (int)(Math.random() * 256);
							int b = (int)(Math.random() * 256);
							label.setBackground(new Color(r, g, b));
						}
						
						public void mouseClicked(MouseEvent e)
						{
							if (e.getClickCount() == 2)
							{
								JLabel label = (JLabel)e.getSource();
								label.setBackground(Color.WHITE);
							}						
						}
					});
		}
		setSize(300, 150);
		setVisible(true);
	}
	
	public static void main(String[] args)
	{
		new Program9_2();		
	}
}
