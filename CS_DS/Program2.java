import java.util.Scanner;

public class Program2 
{
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) 
    {
        Program2_3();

        scanner.close();

    }


    public static void Program2_1()
    {
        // Java에는 C의 sizeof과 같이 변수의 크기를 알 수 있는 연산자가 없다.
    }

    public static void Program2_2()
    {
        int scores[] = {91, 86, 97};
        char grades[] = {'A', 'B', 'A'};

        System.out.print("\n *** 학년별 취득 학점 *** \n\n");
        
        for (int i = 0; i < 3; i++) 
        {
            System.out.println((i+1) + "학년 : 총점 = " + scores[i] + ", 등급 = " + grades[i]);
        }
    }

    public static void Program2_3()
    {
        int i = 0, n;
        int multiply[] = new int[9];

        System.out.print("\n1~9의 정수를 입력하세요 : ");

        while (true)
        {
            n = scanner.nextInt();
            if (n < 0 || n > 9)
            {
                System.out.print("\n 1~9의 정수를 입력하세요 : ");
            }
            else
            {
                break;
            }
        }

        System.out.print("\n");

        for (i = 0; i < 9; i++)
        {
            multiply[i] = n * (i + 1);
            System.out.print(n + " * " + (i + 1) + " = " +  multiply[i] + "\n");
        }
    }


    public static void Program2_4()
    {
        String s = "Data Structure!";
        char[] str = s.toCharArray();

        System.out.print("\n문자 배열 str[] : ");
        for (int i = 0; i < str.length; i++)
        {
            System.out.print(str[i]);
        }
    }
    
    public static void Program2_5()
    {
        int length = 0;
        char[] str = new char[50];
        System.out.print("\n문자열을 입력하세요 : ");
        String s = scanner.next();
        str = s.toCharArray();
        System.out.print("\n입력된 문자열은 \n \"");
        for (int i = 0; i < str.length; i++)
        {
            System.out.print(str[i]);
            length += 1;
        }
        System.out.print("\" \n입니다.");
        System.out.print("\n\n입력된 문자열의 길이 = " + length + " \n");
    }
    
    public static  void Program2_6()
    {
        int[][][] array = new int[2][3][4];
        int i, j, k, value = 1;
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 3; j++)
            {
                for (k = 0; k < 4; k++)
                {
                    array[i][j][k] = value;
                    System.out.print(String.format("\n array[%d][%d][%d] = %d", i, j, k, array[i][j][k]));
                    value++;
                }
            }
        }
    }
    
    public static void Program2_7()
    {
        int i, j, k;
        char[][][] student = new char[2][3][20];
        for (i = 0; i < 2; i++)
        {
            System.out.print(String.format("\n 학생 %d의 이름 : ", i + 1));
            String s = scanner.next();
            student[i][0] = s.toCharArray();
            System.out.print(String.format("\n 학생 %d의 학과 : ", i + 1));
            s = scanner.next();
            student[i][1] = s.toCharArray();;
            System.out.print(String.format("\n 학생 %d의 학번 : ", i + 1));
            s = scanner.next();
            student[i][2] = s.toCharArray();
        }
    
        for (i = 0; i < 2; i++)
        {
            System.out.print(String.format("\n\n 학생 %d", i + 1));
            for (j = 0; j < 3; j++)
            {
                System.out.print("\n\t");
                for (k = 0; student[i][j][k] != '0'; k++)
                {
                    System.out.print(String.format("%c", student[i][j][k]));
                }
            }
        }
    }
    
    public static void Program2_8()
    {
        // 자바에서는 포인터를 기본적으로 지원하지 않음
    }
    
    public static void Program2_9()
    {
        // 자바에서는 포인터를 기본적으로 지원하지 않음
    }
    
    public static void Program2_10()
    {
        // 자바에서는 포인터를 기본적으로 지원하지 않음
    }
    
    public static void Program2_11()
    {
        // 자바에서는 포인터를 기본적으로 지원하지 않음
    }
    
    //
    
    public static void Program2_12()
    {
        // 자바에서는 구조체를 기본적으로 지원하지 않음
    }
    
    
    public static void Program2_13()
    {
        // 자바에서는 구조체와 포인터를 기본적으로 지원하지 않음
    }
    
    //
    
    public static long fact(int n)
    {
        long value;
        if (n <= 1)
        {
            System.out.print("\n fact(1) 함수 호출!");
            System.out.print("\n fact(1) 값 1 반환!!");
            return 1;
        }
        else
        {
            System.out.print(String.format("\n fact(%d) 함수 호출!", n));
            value = (n * fact(n - 1));
            System.out.print(String.format("\n fact(%d) 값 %ld 반환!!", n, value));
            return value;
        }
    }
    
    public static void Program2_14()
    {
        int n;
        long result;
        System.out.print("\n 정수를 입력하세요 : ");
        n = scanner.nextInt();
        result = fact(n);
        System.out.print(String.format("\n\n %d의 팩토리얼 값은 %ld입니다.\n", n, result));
    }
    
    //
    
    public static void hanoi(int n, int start, int work, int target)
    {
        if (n == 1)
        {
            System.out.print(String.format(" %c에서 원반 %d를(을) %c로 옮김 \n", start, n, target));
        }
        else
        {
            hanoi(n - 1, start, target, work);
            System.out.print(String.format(" %c에서 원반 %d를(을) %c로 옮김 \n", start, n, target));
            hanoi(n - 1, work, start, target);
        }
    }
    
    public static void Program2_15()
    {
        hanoi(3, 'A', 'B', 'C');
    }
}