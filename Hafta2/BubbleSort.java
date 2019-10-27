import java.util.Scanner;

public class BubbleSort {

    public static boolean isPrime(int num) {
        if (num < 2) return false;
        int limit = (num / 2) + 1;

        for (int i = 2; i < limit; i++) {
            if (num % i == 0) return false;
        }

        return true;
    }

    public static void bubbleSort(int[] array) {
        for (int i = 0; i < array.length - 1; i++)
            for (int j = 0; j < array.length - i - 1; j++)
                if (array[j] > array[j + 1]) {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
    }

    public static void printArray(int[] array){
        for (int i = 0; i < 2; i++) {
            for(int item : array){
                switch (i){
                    case 0:
                        if (isPrime(item))
                            System.out.print(item + " ");
                        break;

                    case 1:
                        if (!isPrime(item))
                            System.out.print(item + " ");
                        break;
                }
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int row = scan.nextInt();
        int column = scan.nextInt();

        int[][] matrix = new int[row][column];

        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                matrix[i][j] = scan.nextInt();
            }
        }

        for (int[] items : matrix) {
            bubbleSort(items);
            printArray(items);
        }
    }
}
