import java.util.Scanner;
public class ProgramEx 
{

	public static void main(String[] args) 
	{
		// 각 개체를 생성자를 통해 초기화하고 Describe 함수 호출
		
		Student student = new Student(2, 4);
		student.describe();
		
		StudentWorker studentWorker = new StudentWorker(2, 4, 100, "Programmer");
		studentWorker.describe();
		
		Researcher researcher = new Researcher("ABC Lab", "Game");
		researcher.describe();
		
		Professor professor = new Professor("ABC Lab", "Game", "GWNU", 5);
		professor.describe();
	}

}

abstract class Person
{
	// 가장 기본이 되는 클래스
	// 말하기, 먹기, 걷기, 자기 함수가 구현되어 있고
	// 추상 메소드로 Describe가 있다
	
	protected void Talk()
	{
		System.out.println("I can talk.");
	}
	
	protected void Eat()
	{
		System.out.println("I can eat.");
	}
	
	protected void Walk()
	{
		System.out.println("I can walk.");
	}
	
	protected void Sleep()
	{
		System.out.println("I can sleep.");
	}
	
	abstract public void describe();
}

class Student extends Person
{
	// Person 추상 클래스를 부모로하는 Student 클래스
	// 공부 메소드, Describe 메소드와 현재 학년, 점수 필드가 구현되어 있다.
	int curGrade;
	int curScore;
	public Student(int curGrade, int curScore)
	{
		this.curGrade = curGrade;
		this.curScore = curScore;
	}
	protected void Study()
	{
		System.out.println("I can study");
	}
	
	@Override
	public void describe() {
		System.out.println("Student Describe = curGrade : " + curGrade + ", curScore : " + curScore);
	}
	
}

class StudentWorker extends Student
{
	// Student 클래스를 부모로하는 StudentWorker 클래스
	// 일 메소드, Describe 메소드와 돈, 직업 필드가 구현되어 있다.
	int money;
	String job;
	public StudentWorker(int curGrade, int curScore, int money, String job)
	{
		super(curGrade, curScore);
		this.money = money;
		this.job = job;
	}
	protected void Work()
	{
		System.out.println("I can Work");
	}

	@Override
	public void describe() {
		System.out.println("StudentWorker Describe = curGrade : " + curGrade + ", curScore : " + curScore+ ", money : " + money+ ", job : " + job);
	}
	
}

class Researcher extends Person
{
	// Person 클래스를 부모로하는 Researcher 클래스
	// 연구 메소드, Describe 메소드와 연구소, 분야 필드가 구현되어 있다.
	String laboratory;
	String department;
	public Researcher(String laboratory, String department)
	{
		this.laboratory = laboratory;
		this.department = department;
	}
	protected void Research()
	{
		System.out.println("I can Research");
	}
	
	@Override
	public void describe() {
		System.out.println("Researcher Describe = laboratory : " + laboratory + ", department : " + department);
	}
	
}

class Professor extends Researcher
{
	// Researcher 클래스를 부모로하는 Professor 클래스
	// 가르치기 메소드, Describe 메소드와 대학, 논문 수 필드가 구현되어 있다.
	
	String university;
	int thesisCount;
	public Professor(String laboratory, String department, String university, int thesisCount)
	{
		super(laboratory, department);
		this.university = university;
		this.thesisCount = thesisCount;
	}
	protected void Teach()
	{
		System.out.println("I can Teach");
	}
	
	@Override
	public void describe() {
		System.out.println("Professor Describe = laboratory : " + laboratory + ", department : " + department + ",university : " + university + ", thesisCount : " + thesisCount);
	}
	
}