// Çà·Ä µ¡¼À
public class MatrixAddition {
    public static void main(String[] args) {
        int[][] a = { {1, 2}, {3, 4} };
        int[][] b = { {5, 6}, {7, 8} };

        int rows = a.length;
        int columns = a[0].length;

        int[][] result = new int[rows][columns];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                result[i][j] = a[i][j] + b[i][j];
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                System.out.print(result[i][j] + " ");
            }
            System.out.println();
        }
    }
}

// Çà·Ä °ö¼À
public class MatrixMultiplication {
    public static void main(String[] args) {
        int[][] a = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
        int[][] b = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };

        int rows1 = a.length;
        int columns1 = a[0].length;
        int columns2 = b[0].length;

        int[][] result = new int[rows1][columns2];

        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < columns2; j++) {
                for (int k = 0; k < columns1; k++) {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }

        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < columns2; j++) {
                System.out.print(result[i][j] + " ");
            }
            System.out.println();
        }
    }
}