import java.util.Scanner;

public class Program2_2 {
    public static void main(String[] args) {

        int[] arr = new int[10];
        Scanner scanner = new Scanner(System.in);

        for (int i = 0; i < 10; i++) {
            arr[i] = scanner.nextInt();
        }

        for (int i = 0; i < 10; i++) {
            System.out.print(arr[i] + " ");
        }

        for (int i = 0; i < 9; i++) {
            for (int j = i + 1; j < 10; j++) {
                if (arr[i] == arr[j])
                {
                    System.out.print(arr[i] + "중복됨");
                }
            }
        }

        scanner.close();
    }
}