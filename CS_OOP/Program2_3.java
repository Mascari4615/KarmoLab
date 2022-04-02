public class Program2_3 {
    public static void main(String[] args) {
        
        int[] arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        int min = arr[0], max = arr[0];

        for (int i = 0; i < 10; i++) {
            System.out.print(arr[i] + " ");
        }

        for (int i = 0; i < 10; i++) {
            if (min > arr[0]) {
                min = arr[0];
            }
            if (max < arr[0]) {
                max = arr[0];
            }
        }
    }
}