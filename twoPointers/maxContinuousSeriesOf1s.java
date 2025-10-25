package twoPointers;

import java.util.ArrayList;
import java.util.Queue;

public class maxContinuousSeriesOf1s {
    public ArrayList<Integer> maxone(ArrayList<Integer> A, int B) {
        Queue<Integer> zeroIndices = new java.util.LinkedList<>();
        ArrayList<Integer> resultIndices = new ArrayList<>();
        int left = 0, maxLen = 0, n = A.size();
        for (int right = 0; right < n; right++) {
            if (A.get(right) == 0) {
                zeroIndices.add(right);
            }
            while (zeroIndices.size() > B) {
                left = zeroIndices.poll() + 1;
            }
            if (right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                resultIndices.clear();
                for (int i = left; i <= right; i++) {
                    resultIndices.add(i);
                }
            }
        }
        return resultIndices;
    }
}
