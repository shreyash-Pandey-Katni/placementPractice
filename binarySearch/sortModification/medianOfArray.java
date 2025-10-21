package binarySearch.sortModification;

import java.util.ArrayList;
import java.util.List;

public class medianOfArray {
    public double findMedianSortedArraysBruteForce(final List<Integer> a, final List<Integer> b) {
        // brute force approach

        int leftIndexA = 0, rightIndexA = a.size() - 1, leftIndexB = 0, rightIndexB = b.size() - 1;
        ArrayList<Integer> subArray = new ArrayList<>();
        while (leftIndexA <= rightIndexA && leftIndexB <= rightIndexB) {
            if (a.get(leftIndexA) >= b.get(leftIndexB)) {
                subArray.add(b.get(leftIndexB++));
            } else {
                subArray.add(a.get(leftIndexA++));
            }
        }
        while (leftIndexA <= rightIndexA) {
            subArray.add(a.get(leftIndexA++));
        }
        while (leftIndexB <= rightIndexB) {
            subArray.add(b.get(leftIndexB++));
        }
        if (subArray.size() % 2 == 1) {
            return subArray.get(subArray.size() / 2);
        }
        return (subArray.get(subArray.size() / 2) + subArray.get(subArray.size() / 2 - 1)) / 2.0;
    }

    public double findMedianSortedArrays(final List<Integer> a, final List<Integer> b) {
        // brute force approach
        int start = 0, end, partitionX, partitionY, sizeA = a.size(), sizeB = b.size(), totalSize = sizeA + sizeB, leftA, leftB, rightA, rightB;
        if (sizeA == 0){
            return sizeB % 2 == 0 ? (b.get(sizeB/2) + b.get(sizeB/2 - 1)) / 2.0 : b.get(sizeB/2);
        } else if (sizeB == 0){
            return sizeA % 2 == 0 ? (a.get(sizeA/2) + a.get(sizeA/2 - 1)) / 2.0 : a.get(sizeA/2);
        }
        if (sizeA >= sizeB) {
            end = b.size();
            while (start <= end) {
                partitionX = (start + end) / 2;
                partitionY = (totalSize + 1) / 2 - partitionX;
                leftA = partitionY == 0 ? Integer.MIN_VALUE : a.get(partitionY - 1);
                leftB = partitionX == 0 ? Integer.MIN_VALUE : b.get(partitionX - 1);
                rightA = partitionY == sizeA ? Integer.MAX_VALUE : a.get(partitionY);
                rightB = partitionX == sizeB ? Integer.MAX_VALUE : b.get(partitionX);
                if (leftA <= rightB && leftB <= rightA) {
                    return totalSize % 2 == 0
                            ? ((Math.max(leftA, leftB) + Math.min(rightA, rightB)) / 2.0)
                            : (Math.max(leftA, leftB));
                } else if (leftB > rightA) {
                    end = partitionX - 1;
                } else {
                    start = partitionX + 1;
                }
            }
        } else {
            return findMedianSortedArrays(b, a);
        }
        return -1.0;
    }

    public static void main(String[] args) {
//         A : [ -35, -30, 22, 27, 33, 35, 40, 50 ]
// B : [ -39, -28, -25, -17, 1, 30, 33, 37 ]
        ArrayList<Integer> A = new ArrayList<>();
        ArrayList<Integer> B = new ArrayList<>();

        A.add(-35);
        A.add(-30);
        A.add(22);
        A.add(27);
        A.add(33);
        A.add(35);
        A.add(40);
        A.add(50);
        B.add(-39);
        B.add(-28);
        B.add(-25);
        B.add(-17);
        B.add(1);
        B.add(30);
        B.add(33);
        B.add(37);

        medianOfArray obj = new medianOfArray();
        System.out.println(obj.findMedianSortedArrays(A, B));
    }
}
