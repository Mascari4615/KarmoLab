import java.util.Scanner;

public class Program2 {

    public static void Main(String[] args) {
        /*
         * float x = 1;
         * float y = 2;
         * Program2_21(&x, &y);
         */

        /*
         * char* string;
         * while ((string = (char*)malloc(sizeof(char) * 100)) == NULL);
         * scanf("%s", string);
         * while (getchar() != '\n');
         * string = (char*)realloc(string, strlen(string) + 1);
         * Program2_22(string);
         * printf("%s", string);
         */

        /*
         * char* string;
         * while ((string = (char*)malloc(sizeof(char) * 100)) == NULL);
         * scanf("%s", string);
         * while (getchar() != '\n');
         * string = (char*)realloc(string, strlen(string) + 1);
         * Program2_23(string);
         */

        // printf("%d", Program2_25(3));
        // printf("%d", Program2_26(3));
    }

    public static void Program2_17() {

        int[] subject1Scores = new int[10];
        int[] subject2Scores = new int[10];
        int[] subject3Scores = new int[10];

        Scanner scanner = new Scanner(System.in);

        for (int i = 0; i < 10; i++) {
            System.out.println(i + "%학번 학생의 성적 입력");
            subject1Scores[i] = scanner.nextInt();
            subject2Scores[i] = scanner.nextInt();
            subject3Scores[i] = scanner.nextInt();
        }

        for (int i = 0; i < 10; i++) {
            int total = subject1Scores[i] + subject2Scores[i] + subject3Scores[i];
            float average = (float) total / 3;
            System.out.println("학번\t국어\t영어\t수학\t총점\t평균");
            System.out.println("**************************************\n");
            System.out.println(i + '\t' + subject1Scores[i] + '\t' + subject2Scores[i] + '\t' + subject3Scores[i] + '\t'
                    + total + '\t' + average);
        }

        scanner.close();
    }

    public static void Program2_18() {
        int[] arr = { 19, 2, 25, 92, 36, 45 };

        System.out.println("배열 요소 출력");
        for (int i = 0; i < 6; i++) {
            System.out.print(arr[i] + " ");
        }

        System.out.println("\n\n최솟값 최댓값 출력");
        int min = arr[0], max = arr[0];
        for (int i = 0; i < 6; i++) {
            if (min > arr[i])
                min = arr[i];

            if (max < arr[i])
                max = arr[i];
        }
        System.out.print(min + " " + max);

        System.out.println("\n\n평균 출력\n");
        int total = 0;
        float average = 0;
        for (int i = 0; i < 6; i++) {
            total += arr[i];
        }
        System.out.println(average = (float) total / 6);

        System.out.println("\n\n분산 출력");
        float variance = 0;
        for (int i = 0; i < 6; i++) {
            variance += Math.pow(arr[i] - average, 2);
        }
        System.out.println(variance /= 6);
    }

    public static void Program2_19() {
        String[] strings = new String[5];
        Scanner scanner = new Scanner(System.in);

        for (int i = 0; i < 5; i++) {
            strings[i] = scanner.next();
        }

        for (int i = 0; i < 5; i++) {
            System.out.print(strings[i]);
        }
        scanner.close();
    }

    public static void Program2_20() {
        Scanner scanner = new Scanner(System.in);
        String stringA = scanner.next();
        String stringB = scanner.next();

        if (stringA.equals(stringB)) {
            System.out.print("문자열 같음");
        } else {
            System.out.print("문자열 다름");
        }

        scanner.close();
    }

// void Program2_21(float*x, float*y)
// {
// 	float* tmp = x;
// 	x = y;
// 	y = tmp;

// 	printf("%f %f", *x, *y);
// }

// void Program2_22(char *s)
// {
// 	while (*s != 0)
// 	{
// 		if (*s >= 'A' && *s <= 'Z')
// 		{
// 			*s = *s + 32;
// 		}
// 		else if (*s >= 'a' && *s <= 'z')
// 		{
// 			*s = *s - 32;
// 		}
// 		s++;
// 	}
// }

// void Program2_23(char* s)
// {
// 	for (int i = strlen(s) - 1; i >= 0; i--)
// 	{
// 		printf("%c", s[i]);
// 	}
// }

    void Program2_24() {

    }

    int Program2_25(int n) {
        if (n < 1) {
            return n;
        }

        return n + Program2_25(n - 1);
    }

    int Program2_26(int n) {
        if (n == 0 || n == 2) {
            return n;
        } else {
            return Program2_26(n - 1) + Program2_26(n - 2);
        }
    }

}