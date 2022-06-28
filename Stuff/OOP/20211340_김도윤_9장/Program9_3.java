import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Program9_3 extends JFrame 
{
	private FirstPanel fisrtPanel;
	
	public Program9_3() 
	{
		setTitle("Program9_3");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();		
		c.setLayout(new BorderLayout());
		
		fisrtPanel = new FirstPanel();
		c.add(fisrtPanel, BorderLayout.NORTH);
		c.add(new SecondPanel(), BorderLayout.CENTER);
		
		setSize(300, 300);
		setVisible(true);

	}
	
	private class FirstPanel extends JPanel 
	{
		private JLabel[] labels = new JLabel[100];
		private int lastIndex = 0;
		private boolean isNumvering = false;
		
		public FirstPanel() 
		{
			add(labels[lastIndex] = new JLabel("Start"));
			setLayout(new GridLayout(lastIndex + 5, 1));		
		}
		
		public void PrintText(String txt)
		{
			add(labels[++lastIndex] = new JLabel());
			setLayout(new GridLayout(lastIndex + 5, 1));		
			labels[lastIndex].setText(txt);
			isNumvering = false;
		}
		
		public void ClearText()
		{
			labels[lastIndex].setText(" ");
		}
		
		public void InputNum(int i)
		{
			if (isNumvering)
			{
				labels[lastIndex].setText(labels[lastIndex].getText() + String.valueOf(i));
			}
			else
			{
				add(labels[++lastIndex] = new JLabel());
				setLayout(new GridLayout(lastIndex + 5, 1));
				labels[lastIndex].setText(labels[lastIndex].getText() + String.valueOf(i));
				isNumvering = true;
			}		
		}
	}
	
	private class SecondPanel extends JPanel 
	{
		public SecondPanel() 
		{
			setLayout(new GridLayout(5, 3));
			
			JButton btn = new JButton("Call");
			btn.addActionListener(new MyActionListener());
			add(btn);
			btn = new JButton("Delete");
			btn.addActionListener(new MyActionListener());
			add(btn);
			btn = new JButton("Hang up");
			btn.addActionListener(new MyActionListener());
			add(btn);

			for(int i = 0; i < 9; i++) 
			{
				btn = new JButton(Integer.toString(i + 1));
				btn.addActionListener(new MyActionListener());
				add(btn);
			}
			
			btn = new JButton("*");
			btn.addActionListener(new MyActionListener());
			add(btn);
			btn = new JButton("0");
			btn.addActionListener(new MyActionListener());
			add(btn);
			btn = new JButton("#");
			btn.addActionListener(new MyActionListener());
			add(btn);		
		}
	}
	
	private class MyActionListener implements ActionListener 
	{
		public void actionPerformed(ActionEvent e) 
		{
			JButton btn = (JButton)e.getSource();
			
			if(btn.getText().equals("Call")) 
			{
				fisrtPanel.PrintText("Calling\n");
			}
			else if(btn.getText().equals("Delete")) 
			{
				fisrtPanel.ClearText();
			}		
			else if(btn.getText().equals("Hang up"))  
			{
				fisrtPanel.PrintText("Hang up\n");
			}
			else
			{
				fisrtPanel.InputNum(Integer.parseInt(btn.getText()));
			}
		}
	}
	
	public static void main(String args[]) 
	{
		new Program9_3();
	}
}