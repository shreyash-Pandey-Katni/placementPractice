import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.SortedSet;
import java.util.TreeSet;

public class largestNumber {
    public String largestNumber(final List<Integer> A) {
        String result = "";
        HashMap<Integer, ArrayList<String>> bucket = new HashMap<>();
        // for (Integer integer : A) {
        //     int bucketIndex = (int) (integer / (Math.pow(10,(int)  (Math.log10(integer)))));
        //     if (!bucket.containsKey(bucketIndex)) {
        //         bucket.put(bucketIndex, new ArrayList<>());
        //     }
        //     bucket.get(bucketIndex).add(String.valueOf(integer));
        // }
        // for (int i = 9; i >= 0; i--) {
        //     if (bucket.containsKey(i)) {
        //         ArrayList<String> listOfIntegers = bucket.get(i);
        //         // Sort the list of integers in descending order based on their string representation
        //         listOfIntegers.sort((a, b) -> (b + a).compareTo(a + b));
        //         for (String integer : listOfIntegers) {
        //             result += integer;
        //         }
        //     }
        // }

        String[] strArray = new String[A.size()];
        for (int i = 0; i < A.size(); i++) {
            strArray[i] = String.valueOf(A.get(i));
        }
        // Sort the array based on custom comparator
        Arrays.sort(strArray, (a, b) -> (b + a).compareTo(a + b));
        // Build the result string
        StringBuilder sb = new StringBuilder();
        for (String str : strArray) {
            sb.append(str);
        }
        result = sb.toString();
        // If the result starts with '0', it means all numbers were zero
        if (result.charAt(0) == '0') {
            return "0"; // If the largest number is zero, return "0"
        }

        // // Remove leading zeros if any
        // while (result.length() > 1 && result.charAt(0) == '0') {
        //     result = result.substring(1);
        // }
        // if (result.isEmpty()) {
        //     return "0"; // If the result is empty, it means all numbers were zero
        // }
        return result;
    }
    public static void main(String[] args) {
        // Calculate time for execution
        long startTime = System.nanoTime();
        largestNumber ln = new largestNumber();
        // A = [3, 30, 34, 5, 9]
        List<Integer> A = new ArrayList<>();
        A.add(3);
        A.add(30);
        A.add(34);
        A.add(5);
        A.add(9);
        String result = ln.largestNumber(A);
        System.out.println("Result:" + result); // Expected output: "9534330"
        long endTime = System.nanoTime();
        long duration = endTime - startTime; // Calculate the duration in nanoseconds
        System.out.println("Time taken: " + duration / 1_000_000_000.0 + " seconds"); // Convert to seconds
    }
}
