package twoPointers;

import java.util.ArrayList;

public class subArraysWithDistinctIntegers {
    private long atMost(ArrayList<Integer> A, int B) {
        if (B < 0) {
            return 0;
        }
        int n = A.size();
        int[] freq = new int[n + 1];
        long count = 0, distinct = 0;
        int left = 0;
        for (int right = 0; right < n; right++) {
            int current = A.get(right);
            if (freq[current]++ == 0) {
                distinct++;
            }
            while (distinct > B) {
                if (--freq[A.get(left)] == 0) {
                    distinct--;
                }
                left++;
            }
            count += right - left + 1;
        }
        return (int) count;
    }

    public int solve(ArrayList<Integer> A, int B) {
        if (B == 0) {
            return 0;
        } else if (B == 1) {
            return A.size();
        }
        return (int) (atMost(A, B) - atMost(A, B - 1));
    }

    public static void main(String[] args) {
        ArrayList<Integer> A = new ArrayList<>();
        A.add(5);
        A.add(3);
        A.add(5);
        A.add(1);
        A.add(3);
        subArraysWithDistinctIntegers obj = new subArraysWithDistinctIntegers();
        System.out.println(obj.solve(A, 3));
    }
}
