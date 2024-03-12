package laba1;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Input size of matrix (NxN): \n>");
        int n;
        while(true) {
        	n = scanner.nextInt();
	        if(n<=0) System.out.println("Incorrect size!");
	        else break;
        }

        double[][] matrix = new double[n][n];

        System.out.println("Input elements of matrix:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(">");
                matrix[i][j] = scanner.nextDouble();
            }
        }

        System.out.println("Your matrix:");
        printMatrix(matrix);

        double det = determinant(matrix);
        System.out.println("Determinant of matrix: " + det);
    }

    public static void printMatrix(double[][] matrix) {
        int size_of_matrix = matrix.length;
        for (int i = 0; i < size_of_matrix; i++) {
            for (int j = 0; j < size_of_matrix; j++) {
                System.out.print(matrix[i][j] + " | ");
            }
            System.out.println();
        }
    }

    public static double determinant(double[][] matrix) {
        int n = matrix.length;
        if (n == 1) {
            return matrix[0][0];
        }

        double det = 0;
        double[][] submatrix = new double[n - 1][n - 1];

        for (int i = 0; i < n; i++) {
            int subi = 0;
            for (int j = 1; j < n; j++) {
                int subj = 0;
                for (int k = 0; k < n; k++) {
                    if (k == i) continue;
                    submatrix[subi][subj] = matrix[j][k];
                    subj++;
                }
                subi++;
            }
            det += (i % 2 == 0 ? 1 : -1) * matrix[0][i] * determinant(submatrix);
        }

        return det;
    }
}