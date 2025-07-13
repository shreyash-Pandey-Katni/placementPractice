package math.arrayDP;

import java.util.ArrayList;

public class numberOfLengthNAndValueLessThanK {

    // Write most efficient code for factorial using memoization and modular
    // arithmetic

    private int lowerBound(ArrayList<Integer> A, int key) {
        int left = 0, right = A.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (A.get(mid) < key)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }

    private int power(int base, int exp) {
        int result = 1;
        while (exp > 0) {
            result *= base;
            exp--;
        }
        return result;
    }

    public int solve(ArrayList<Integer> A, int B, int C) {
        if (B <= 0 || C <= 0 || A.isEmpty()) {
            return 0;
        }
        int lengthOfC = (int) Math.log10(C) + 1;
        // Case 1: B>C ouput 0
        if (B > lengthOfC) {
            return 0;
        }
        if (B == 1) {
            int pos = lowerBound(A, C);
            return pos;
        }
        // Case 2: B<C output all combinations
        if (B < lengthOfC) {
            int lengthOfA = A.contains(0) ? A.size() - 1 : A.size();
            if (A.contains(0)) {
                return lengthOfA * (power(A.size(), B - 1));
            }
            return power(A.size(), B);
        }
        String stringC = String.valueOf(C);
        char[] charArray = stringC.toCharArray();
        int res = 0;
        for (int i = 0; i < charArray.length; i++) {
            int pos = lowerBound(A, charArray[i] - '0');
            if (i == 0 && A.get(0) == 0 && B > 1) {
                // If the first digit is 0 and B > 1, we cannot use 0 as the first digit
                pos--;
            }
            res += pos * (power(A.size(), B - i - 1));
            if (pos == A.size() || !A.contains(charArray[i] - '0')) {
                // If the current digit is not in A, we cannot form a valid number
                return res;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        numberOfLengthNAndValueLessThanK obj = new numberOfLengthNAndValueLessThanK();
        ArrayList<Integer> A = new ArrayList<>();
        // A : [ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ]
        // B : 7
        // C : 97300910
        for (int i = 0; i <= 9; i++) {
            A.add(i);
        }
        int B = 7;
        int C = 97300910;
        int result = obj.solve(A, B, C);
        System.out.println("Result: " + result);
    }
}
