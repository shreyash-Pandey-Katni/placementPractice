package math;

import java.util.ArrayList;

public class divisibleBy60 {
    public int divisibleBy60(ArrayList<Integer> A) {
        int n = A.size();
        long sum = 0;
        int countZero = 0;
        int countEven = 0;
        for (Integer ele : A) {
            if (ele == 0) {
                countZero++;
            }
            if (ele % 2 == 0) {
                countEven++;
            }
            sum += ele;
        }
        if (sum % 3 != 0) {
            return 0;
        }
        if (countZero == 0 || countEven < 1) {
            return 0;
        } else if (countZero == 1 && countEven == 1 && n != 1) {
            return 0;
        }
        return 1;
    }

    public static void main(String[] args) {
        divisibleBy60 obj = new divisibleBy60();
        ArrayList<Integer> A = new ArrayList<>();
        // A.add(3);
        A.add(0);
        System.out.println(obj.divisibleBy60(A)); // Output: 1

        ArrayList<Integer> B = new ArrayList<>();
        B.add(1);
        B.add(2);
        B.add(3);
        System.out.println(obj.divisibleBy60(B)); // Output: 0
    }
}
