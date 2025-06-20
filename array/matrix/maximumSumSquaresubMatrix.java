import java.util.ArrayList;

public class maximumSumSquaresubMatrix {
    public int solve(ArrayList<ArrayList<Integer>> A, int B) {
        // Bruteforce method
        int max = Integer.MIN_VALUE;
        int n = A.size();
        int[][] leftBounderies = new int[n - B + 1][n - B + 1];
        for (int i = 0; i < n - B + 1; i++) {
            for (int j = 0; j < n - B + 1; j++) {
                int temp = 0;
                for (int j2 = 0; j2 < B; j2++) {
                    for (int k = 0; k < B; k++) {
                        temp += A.get(i + j2).get(j + k);
                    }
                }
                max = Math.max(max, temp);
            }
        }

        return max;
    }

    public static void main(String[] args) {
        // Calculate time taken to execute the code
        long startTime = System.nanoTime();
        maximumSumSquaresubMatrix obj = new maximumSumSquaresubMatrix();
        ArrayList<ArrayList<Integer>> matrix = new ArrayList<>();
        // A = [
        // [1, 1, 1, 1, 1]
        // [2, 2, 2, 2, 2]
        // [3, 8, 6, 7, 3]
        // [4, 4, 4, 4, 4]
        // [5, 5, 5, 5, 5]
        // ]
        // B = 3
        matrix.add(new ArrayList<>(java.util.Arrays.asList(1, 1, 1, 1, 1)));
        matrix.add(new ArrayList<>(java.util.Arrays.asList(2, 2, 2, 2, 2)));
        matrix.add(new ArrayList<>(java.util.Arrays.asList(3, 8, 6, 7, 3)));
        matrix.add(new ArrayList<>(java.util.Arrays.asList(4, 4, 4, 4, 4)));
        matrix.add(new ArrayList<>(java.util.Arrays.asList(5, 5, 5, 5, 5)));

        int B = 3; // Size of the submatrix
        int result = obj.solve(matrix, B);
        System.out.println("Maximum Sum of " + B + "x" + B + " Submatrix: " + result);
        long endTime = System.nanoTime();
        long duration = endTime - startTime; // Calculate duration in nanoseconds
        System.out.println("Time taken: " + duration + " nanoseconds");
    }
}
