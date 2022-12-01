using System;
using System.Collections.Generic;
using System.Runtime.ConstrainedExecution;

class PS
{
    public static void Main()
    {
        Program2_3();
    }

    public static void Program1_1()
    {
        int num1 = 1;
        int num2 = 1;
        int sum = 2;
        int cur = 0;

        for (int i = 3; i <= 21; i++)
        {
            cur = num1 + num2;
            sum += cur;
            num1 = num2;
            num2 = cur;
            Console.WriteLine($"{i} 번째 항 : {cur}");
            Console.WriteLine($"{i} 번째 합 : {sum}");
        }
    }

    public static int MyCompare(int[] arr1, int[] arr2)
    {
        return (arr1[0] + arr1[1] == arr2[0] + arr1[1]) ? 0 : (arr1[0] + arr1[1] < arr2[0] + arr1[1]) ? 1 : -1;
    }

    public static void Program2_1()
    {
        // 1000 1999 정수 중 임의의 두 수를 골라 덧셈을 했을 때
        // 11의 배수가 되는 쌍들의 총 개수와 이들 쌍 중에서 그 합의 크기를 기준으로 내ㅣ림차순 순서 상 세 번째인 쌍을 구하는 프로그램

        List<int[]> list = new List<int[]>();

        for (int i = 1000; i < 1999; i++)
        {
            for (int j = i + 1; j <= 1999; j++)
            {
                if ((i + j) % 11 == 0)
                {
                    list.Add(new int[] { i, j });
                }
            }
        }

        list.Sort(MyCompare);

        /*Console.WriteLine(list[0][0]);
        Console.WriteLine(list[0][1]);
        Console.WriteLine(list[1][0]);
        Console.WriteLine(list[1][1]);*/

        Console.WriteLine($"쌍의 개수 : {list.Count}");
        Console.WriteLine($"세 번째 쌍 : {list[2][0]}, {list[2][1]}");
    }

    public static int SumToN(int n)
    {
        int sum = 0;

        for (int i = 1; i <= n; i++)
        {
            if (i % 3 != 0)
                sum += i;
        }

        Console.WriteLine($"{n}항 합 : {sum}");
        return sum;
    }

    public static void Program2_2()
    {
        for (int i = 1; true; i++)
        {
            if (SumToN(i) == 17557)
            {
                Console.WriteLine($"{i} 번째 항이 17557 입니다.");
                break;
            }
            else if (SumToN(i) > 17557)
            {
                Console.WriteLine($"17557 은 요소로서 존재하지 않습니다.");
                break;
            }
        }
    }

    public static void Program2_3()
    {
        int sum = 0;
        for (int i = 1; i <= 1000; i++)
        {
            sum += (int)MathF.Round(MathF.Sqrt(i));
        }

        Console.WriteLine($"{sum}");
    }
}