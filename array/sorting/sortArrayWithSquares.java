import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

public class sortArrayWithSquares {
    public ArrayList<Integer> solve(ArrayList<Integer> A) {
        ArrayList<Integer> result = new ArrayList<>();
        for (Integer integer : A) {
            result.add(integer * integer);
        }
        Collections.sort(result);
        return result;
    }
    
    public static void main(String[] args) {
        // Calculate time to execute the code
        long startTime = System.nanoTime();
        sortArrayWithSquares sas = new sortArrayWithSquares();
        // A = [-6, -3, -1, 2, 4, 5]
        ArrayList<Integer> A = new ArrayList<>();
        A.add(-6);
        A.add(-3);
        A.add(-1);
        A.add(2);
        A.add(4);
        A.add(5);
        ArrayList<Integer> result = sas.solve(A);
        for (int num : result) {
            System.out.print(num + " ");
        }
        System.out.println();
        long endTime = System.nanoTime();
        long duration = endTime - startTime; // Calculate the duration in nanoseconds
        System.out.println("Time taken: " + duration / 1_000_000_000.0 + " seconds"); // Convert to seconds
    }
}
