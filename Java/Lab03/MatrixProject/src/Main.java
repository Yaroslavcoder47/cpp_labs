import java.io.FileNotFoundException;
import java.util.Scanner;
import java.io.File;

public class Main {
    public static void main(String[] args) {
        try{
            int[][] matrix = getMatrix();
            for(int[] i : matrix){
                for(int j : i){
                    System.out.print(j + " ");
                }
                System.out.println();
            }
            System.out.println("Local Minimum");
            localMinimum(matrix);
            System.out.println("Local Maximum");
            localMaximum(matrix);
        }
        catch(IllegalArgumentException | FileNotFoundException exc){
            System.out.println(exc.getMessage());
        }
    }

    public static int[][] getMatrix() throws FileNotFoundException{
        String path = "data/input.txt";
        Scanner scan = new Scanner(new File(path));

        int n = scan.nextInt();
        int m = scan.nextInt();
        if (n <= 0 || m <= 0) {
            throw new IllegalArgumentException("Wrong arguments");
        }

        int[][] matrix = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!scan.hasNextInt()) {
                    throw new IllegalArgumentException("Not enough elements");
                }
                matrix[i][j] = scan.nextInt();
            }
        }

        if (scan.hasNextInt()) {
            throw new IllegalArgumentException("Too much arguments");
        }
        scan.close();
        return matrix;
    }


    public static void localMinimum(int[][] matr){
        for(int i = 0 ; i < matr.length; i++) {
            for (int j = 0; j < matr[i].length; j++) {
                int currentElement = matr[i][j];
                int count = 0;
                int countDirections = 0;
                if (i - 1 >= 0) {
                    countDirections++;
                    if (currentElement < matr[i - 1][j]) {
                        count++;
                    }
                }
                if (i + 1 < matr.length) {
                    countDirections++;
                    if (currentElement < matr[i + 1][j]) {
                        count++;
                    }
                }
                if (j - 1 >= 0) {
                    countDirections++;
                    if (currentElement < matr[i][j - 1]) {
                        count++;
                    }
                }
                if (j + 1 < matr[i].length) {
                    countDirections++;
                    if (currentElement < matr[i][j + 1]) {
                        count++;
                    }
                }
                if (count == countDirections) {
                    System.out.println("(" + i + "; " + j + ")");
                }
            }
        }
    }

    public static void localMaximum(int[][] matr){
        for(int i = 0 ; i < matr.length; i++) {
            for (int j = 0; j < matr[i].length; j++) {
                int currentElement = matr[i][j];
                int count = 0;
                int countDirections = 0;
                if (i - 1 >= 0) {
                    countDirections++;
                    if (currentElement > matr[i - 1][j]) {
                        count++;
                    }
                }
                if (i + 1 < matr.length) {
                    countDirections++;
                    if (currentElement > matr[i + 1][j]) {
                        count++;
                    }
                }
                if (j - 1 >= 0) {
                    countDirections++;
                    if (currentElement > matr[i][j - 1]) {
                        count++;
                    }
                }
                if (j + 1 < matr[i].length) {
                    countDirections++;
                    if (currentElement > matr[i][j + 1]) {
                        count++;
                    }
                }
                if (count == countDirections) {
                    System.out.println("(" + i + "; " + j + ")");
                }
            }
        }
    }
}