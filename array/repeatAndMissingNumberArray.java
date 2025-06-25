import java.util.ArrayList;
import java.util.List;

public class repeatAndMissingNumberArray {
    public ArrayList<Integer> repeatedNumber(final List<Integer> A) {
        int n = A.size();
        long sum = 0;
        long sumOfSquares = 0;
        long expectedSum = (long) n * (n + 1) / 2;
        long expectedSumOfSquares = (long) n * (n + 1) * (2 * n + 1) / 6;
        
        for (int i = 0; i < n; i++) {
            int num = A.get(i);
            sum += num;
            sumOfSquares += (long) num * num;
        }
        
        long sumOfSquaresDiff = (long) (sumOfSquares - expectedSumOfSquares);
        long sumDiff = (long) (sum - expectedSum);

        int repeating = (int) ((sumOfSquaresDiff / sumDiff + sumDiff) / 2);

        int missing = (int) (repeating + expectedSum - sum);
        ArrayList<Integer> result = new ArrayList<>();
        result.add(repeating);
        result.add(missing);
        return result;
    }

    public static void main(String[] args) {
        // Calculate time taken to execute the code
        long startTime = System.nanoTime();
        repeatAndMissingNumberArray obj = new repeatAndMissingNumberArray();
        ArrayList<Integer> A = new ArrayList<>();
        // A = [3, 1, 2, 5, 3]
        A.add(3);
        A.add(1);
        A.add(2);
        A.add(5);
        A.add(3);

        ArrayList<Integer> result = obj.repeatedNumber(A);
        System.out.println("Result: " + result);
        long endTime = System.nanoTime();
        long duration = endTime - startTime; // Calculate duration in nanoseconds
        System.out.println("Time taken: " + duration + " nanoseconds");
    }
}
