import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Program9_1 extends JFrame
{	
    private GamePanel panel1;
    public Program9_1()
    {
        setTitle("Open Challenge 9");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();    
        
        panel1 = new GamePanel();
        c.add(panel1, BorderLayout.NORTH);
        JPanel panel2 = new UserPanel();
        c.add(panel2, BorderLayout.CENTER);

        setSize(300, 300);
        setVisible(true);
    }
    public static void main(String [] args)
    {
        new Program9_1();
    }

    class MyActionListener implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            JButton b = (JButton)e.getSource();
            if (b.getText().equals("Action"))
                b.setText("액션");
            else
            	b.setText("Action");
        }
    }
    
    class GamePanel extends JPanel
    {
    	private GameLabel[] gameLabels = new GameLabel[3];
    	
    	public GamePanel()
    	{
    		setLayout(new FlowLayout(FlowLayout.CENTER));
    		add(gameLabels[0] = new GameLabel());
    		add(gameLabels[1] = new GameLabel());
    		add(gameLabels[2] = new GameLabel());
    	}
    	
    	public void SetLabelRandom()
    	{
    		for (int i = 0; i < gameLabels.length; i++)
    		{
    			gameLabels[i].SetRandom();
    		}
    	}
    }
    
    class GameLabel extends JLabel
    {
    	public GameLabel()
    	{
    		setText("0");
    		setBackground(Color.black);
    		setOpaque(true);
    		setForeground(Color.yellow);
    	}
    	
    	public void SetRandom()
    	{
    		setText(String.valueOf((int)(Math.random()*4)));
            int r = (int)(Math.random() * 256);
			int g = (int)(Math.random() * 256);
			int b = (int)(Math.random() * 256);
			setBackground(new Color(r, g, b));
    	}
    }
    
    class UserPanel extends JPanel
    {
        private Label label;
    	public UserPanel()
    	{
    		setLayout(new FlowLayout(FlowLayout.CENTER));
    		add(label = new Label("Start"));
    		
    		Button btn = new Button("Change");
    		btn.addMouseListener(new MouseAdapter()
			{
				public void mousePressed(MouseEvent e)
				{
					panel1.SetLabelRandom();
                    label.setText("Changed");
				}
			});
    		add(btn);
    	}
    }
}