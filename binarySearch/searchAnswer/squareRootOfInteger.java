package binarySearch.searchAnswer;

public class squareRootOfInteger {
    public int sqrt(int A) {
        int lower = 0, upper = A / 2 + 1;
        int mid, res = 1;
        long val;
        long intMaxSQRT = (long) Math.sqrt(Integer.MAX_VALUE);
        upper = Math.min(upper, (int) intMaxSQRT);
        if (A < 2) {
            return A;
        }
        while (lower <= upper) {
            mid = lower + (upper - lower) / 2;
            val = mid * mid;
            if (val <= A) {
                res = mid;
                lower = mid + 1;
            } else {
                upper = mid - 1;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        // int A = 11;
        squareRootOfInteger obj = new squareRootOfInteger();
        // int result = obj.sqrt(A);
        // System.out.println("The square root of " + A + " is: " + result);
        // A = 16;
        // result = obj.sqrt(A);
        // System.out.println("The square root of " + A + " is: " + result);
        int A = 930675566;
        int result = obj.sqrt(A);
        System.out.println("The square root of " + A + " is: " + result);
    }
}
