import java.util.Scanner;

abstract class Calculator
{
	// 계산기들의 부모 클래스 (추상)
	
	protected int a, b; // 계산할 정수 2개
	abstract protected int calc(); // 계산 기능을 구현할 추상 메소드
	public void SetNums(int a, int b) // 정수 초기화
	{
		this.a = a;
		this.b = b;
	}
	public void run() // 계산 및 출력 실행
	{
		int res = calc();
		System.out.println("계산된 값은 " + res);
	}
}

class Adder extends Calculator
{
	// 합 연산
	@Override
	protected int calc() { return a + b; }
}

class Substracter extends Calculator
{
	// 차 연산
	@Override
	protected int calc() { return a - b; }	
}

class Multiplier extends Calculator
{
	// 곱 연산
	@Override
	protected int calc() { return a * b; }
}

class Divider extends Calculator
{
	// 나누기 연산
	@Override
	protected int calc() { return a / b; }
}

public class App
{
	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);
		System.out.print("정수 2개와 연산자를 입력하세요>>");
		int a = scanner.nextInt();
		int b = scanner.nextInt();
		
		// 연산자 입력
		String operator = scanner.next();
		
		// 연산자에 따라 입력받은 숫자를 객체에 초기화 시키고 계산 수행
		switch(operator)
		{
		case "+":
			Adder adder = new Adder();
			adder.SetNums(a, b);
			adder.run();
			break;
		case "-":
			Substracter substracter = new Substracter();
			substracter.SetNums(a, b);
			substracter.run();
			break;
		case "*":
			Multiplier multiplier = new Multiplier();
			multiplier.SetNums(a, b);
			multiplier.run();
			break;
		case "/":
			Divider divider = new Divider();
			divider.SetNums(a, b);
			divider.run();
			break;
		}
	}
}
