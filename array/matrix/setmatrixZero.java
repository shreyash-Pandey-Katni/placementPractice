import java.util.ArrayList;

public class setmatrixZero {
    public void setZeroes(ArrayList<ArrayList<Integer>> a) {
        int n = a.size();
        int m = a.get(0).size();
        
        boolean[] rows = new boolean[n];
        boolean[] col = new boolean[m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a.get(i).get(j) == 0) {
                    rows[i] = true;
                    col[j] = true;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (rows[i]) {
                for (int j = 0; j < m; j++) {
                    a.get(i).set(j, 0);
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            if (col[i]) {
                for (int j = 0; j < n; j++) {
                    a.get(j).set(i, 0);
                }
            }
        }
    }

    public static void main(String[] args) {
        // Initialize time
        long startTime = System.nanoTime();
        ArrayList<ArrayList<Integer>> matrix = new ArrayList<>();
        // Initialize the matrix with some values
        ArrayList<Integer> row1 = new ArrayList<>();
        row1.add(1);
        row1.add(2);
        row1.add(3);
        matrix.add(row1);
        ArrayList<Integer> row2 = new ArrayList<>();
        row2.add(4);
        row2.add(0);
        row2.add(6);
        matrix.add(row2);
        ArrayList<Integer> row3 = new ArrayList<>();
        row3.add(7);
        row3.add(8);
        row3.add(9);
        matrix.add(row3);
        setmatrixZero obj = new setmatrixZero();
        obj.setZeroes(matrix);
        // Calculate and print the execution time
        long endTime = System.nanoTime();
        long duration = endTime - startTime;
        System.out.println("Execution time: " + duration + " nanoseconds");
    }
}
