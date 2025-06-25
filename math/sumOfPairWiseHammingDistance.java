package math;

import java.util.List;

public class sumOfPairWiseHammingDistance {
    public int hammingDistance(final List<Integer> A) {
        
        long modulus = 1000000007; // To handle large numbers, if needed

        // Find number of bits in the largest number
        int numOfBits = 0;
        for (Integer integer : A) {
            numOfBits = Math.max(numOfBits, Integer.toBinaryString(integer).length());
        }

        if (A.size() < 2) {
            return 0; // No pairs to compare
        }
        int n = A.size();
        long totalDistance = 0;
        for (int i = 0; i < numOfBits; i++) {
            long count = 0;
            for (Integer integer : A) {
                if ((integer & (1 << i)) != 0) {
                    count++; // Count how many numbers have the i-th bit set
                }
            }
            totalDistance += ((count%modulus) * (n%modulus - count%modulus) * 2)%modulus; // Each differing pair contributes 2 to the distance
            totalDistance %= modulus; // Keep the total distance within bounds
        }
        return (int) totalDistance;
    }

    public static void main(String[] args) {
        sumOfPairWiseHammingDistance spwhd = new sumOfPairWiseHammingDistance();
        List<Integer> A = List.of(1, 2, 3); // Example input
        int result = spwhd.hammingDistance(A);
        System.out.println("Sum of pairwise Hamming distances: " + result);
        
    }
}
