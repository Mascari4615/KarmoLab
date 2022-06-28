import java.util.Scanner;

public class Program5_4 
{	
	public static void main(String[] args)
	{
		// lineEx 객체를 선언과 동시에 생성자를 통해 초기화
		LineEx lineEx = new LineEx(new Point(1, 2), new Point(3, 4), "Black", 1);
		
		// Start End 출력
		lineEx.DrawLine();
		// Start End 0,0 초기화
		lineEx.DeleteLine();
		// Start End가 0,0으로 초기화 되었는 지 확인
		lineEx.DrawLine();
		// 선의 속성 출력
		lineEx.ShowLine();
	}
}

// 점 클래스
class Point
{
	private int x, y;
	public Point(int x, int y)
	{
		this.x = x;
		this.y = y;
	}
	public int Getx()
	{
		return x;
	}
	public int Gety()
	{
		return y;
	}
	protected void move(int x, int y)
	{
		this.x = x;
		this.y = y;
	}
}

// 선 클래스
class Line
{
	private Point start, end;
	public Line(Point start, Point end)
	{
		this.start = start;
		this.end = end;
	}
	public Point GetStart()
	{
		return start;
	}
	public Point GetEnd()
	{
		return end;
	}
	// Start와 End 를 출력한다
	public void DrawLine()
	{
		System.out.println("Start : (" + start.Getx() + ", " + start.Gety() + "), End : (" + end.Getx() + ", " + end.Gety() + ")");
	}
	// Start와 End를 모두 0,0 으로 초기화시키고, 삭제되었다는 메시지를 출력한다
	public void DeleteLine()
	{
		start.move(0, 0);
		end.move(0, 0);
		System.out.println("Delete Line!");
	}
	protected void move(Point start, Point end)
	{
		this.start = start;
		this.end = end;
	}
}

// 선 클래스를 부모로 하는 LineEx 클래스
class LineEx extends Line
{
	private String color;
	private int thickness;
	public LineEx(Point start, Point end, String color, int thickness) 
	{
		super(start, end);
		this.color = color;
		this.thickness = thickness;
	}
	// 모든 속성을 출력한다
	public void ShowLine()
	{
		System.out.println("Color : " + color + ", Thickness : " + thickness );
	}
}