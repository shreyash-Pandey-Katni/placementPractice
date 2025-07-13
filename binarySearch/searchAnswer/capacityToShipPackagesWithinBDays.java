package binarySearch.searchAnswer;

import java.util.ArrayList;

public class capacityToShipPackagesWithinBDays {
    public int solve(ArrayList<Integer> A, int B) {
        int sum = 0, max = 0;
        for (int i = 0; i < A.size(); i++) {
            sum += A.get(i);
            max = Math.max(max, A.get(i));
        }
        int lower = max, upper = sum;
        int res = 0, mid;
        long tempSum = 0, partition = 1;
        while (lower <= upper) {
            partition = 1;
            tempSum = 0;
            mid = lower + (upper - lower) / 2;
            for (Integer integer : A) {
                if (tempSum + integer > mid) {
                    partition++;
                    tempSum = integer; // Start new partition with current element
                } else {
                    tempSum += integer; // Add to current partition
                }
            }
            if (partition <= B) {
                res = mid;
                upper = mid - 1;
            } else {
                lower = mid + 1;
            }

        }
        return res;
    }

    public static void main(String[] args) {
        // A : [ 16, 2, 11, 4, 18, 17, 17, 8, 8, 6, 7, 9, 17, 20, 10, 5, 2, 11, 3 ]
        // B : 10
        ArrayList<Integer> A = new ArrayList<>();
        int[] arr = { 16, 2, 11, 4, 18, 17, 17, 8, 8, 6, 7, 9, 17, 20, 10, 5, 2, 11, 3 };
        for (int i : arr) {
            A.add(i);
        }
        int B = 10;
        capacityToShipPackagesWithinBDays obj = new capacityToShipPackagesWithinBDays();
        System.out.println(obj.solve(A, B));
    }
}
