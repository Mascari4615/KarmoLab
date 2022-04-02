import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;

public class Program2_1 
{
    public static void main(String[] args) 
    {

        int[] arr1 = new int[5];
        int[] arr2 = new int[5];
        int[] arr3 = new int[10];

        Scanner scanner = new Scanner(System.in);

        for (int i = 0; i < 5; i++) {
            arr1[i] = scanner.nextInt();
        }

        for (int i = 0; i < 5; i++) {
            arr2[i] = scanner.nextInt();
        }

        System.arraycopy(arr1, 0, arr3, 0, 5);
        System.arraycopy(arr2, 0, arr3, 5, 5);
        System.out.print(Arrays.toString(arr3));

        scanner.close();
    }
}