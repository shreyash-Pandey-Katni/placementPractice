package math;

public class stepByStep {
    public int solve(int A) {
        if (A == 1) {
            return 1; // 1 can be formed by just 1

        }
        double val = (Math.sqrt(1 + 4 * 2 * A) - 1) / 2;
        int n = (int) Math.floor(val);
        if (val % 1 == 0 && val == n) {
            return n;
        }
        int k = 0;
        int sum = 0;
        while (sum < Math.abs(A) || (sum - Math.abs(A)) % 2 != 0) {
            k++;
            sum += k;
        }
        return k;
        // int distanceFromSmallerSum = A - (sum - k);
        // int distanceFromLargerSum = sum - A;
        // int numberOfElementsFromSmallerElement = k - 1 + 2 *
        // (distanceFromSmallerSum);
        // int numberOfElementsFromLargerElement = k + 3 * (distanceFromLargerSum);
        // return Math.min(numberOfElementsFromSmallerElement,
        // numberOfElementsFromLargerElement);
    }

    public static void main(String[] args) {
        int result;
        stepByStep obj = new stepByStep();
        // int result = obj.solve(10); // Example input
        // System.out.println(result); // Output: 4 (since 10 can be formed by 1+2+3+4)
        // result = obj.solve(15); // Example input
        // System.out.println(result); // Output: 5 (since 15 can be formed by
        // 1+2+3+4+5)
        result = obj.solve(-35); // Example input
        System.out.println(result); // Output: 1 (since 1 can be formed by just 1)
    }
}
