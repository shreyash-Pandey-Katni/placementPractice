package backtracking;

import java.util.ArrayList;

public class kthPermutationSequence {
    private long[] factorial;
    
    public String getPermutation(int A, int B) {
        ArrayList<Integer> numbers = new ArrayList<>();
        for (int i = 1; i <= A; i++) {
            numbers.add(i);
        }
        
        StringBuilder result = new StringBuilder();
        int k = B - 1; // Convert to 0-indexed
        
        // Build result digit by digit
        for (int i = 0; i < A; i++) {
            int remaining = A - i - 1;
            
            // Calculate factorial of remaining elements
            long factorial = 1;
            for (int j = 1; j <= remaining; j++) {
                factorial *= j;
                // Prevent overflow by capping if it gets too large
                if (factorial > B) break;
            }
            
            // Find which number to pick
            int index = (int)(k / factorial);
            if (index >= numbers.size()) {
                index = numbers.size() - 1;
            }
            
            result.append(numbers.get(index));
            numbers.remove(index);
            
            k = (int)(k % factorial);
        }
        
        return result.toString();
    }
    
    public static void main(String[] args) {
        kthPermutationSequence obj = new kthPermutationSequence();
        
        // Test case 1: Small values
        System.out.println(obj.getPermutation(3, 4)); // Expected: "231"
        
        // Test case 2: Medium values
        System.out.println(obj.getPermutation(4, 9)); // Expected: "2314"
        
        // Test case 3: Large A, reasonable B
        System.out.println(obj.getPermutation(100, 10000000));
    }
}
