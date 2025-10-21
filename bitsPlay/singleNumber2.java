package bitsPlay;

import java.util.List;

public class singleNumber2 {
    public int singleNumber(final List<Integer> A) {
        int[] countArray = new int[32];
        int n = A.size();
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < n; j++) {
                if (A.get(j) == 0) continue;
                countArray[i] += (A.get(j) >> i) & 1;
            }
            countArray[i] %=3;
        }
        int res =0;
        for (int i = 0; i < 32; i++) {
            res += countArray[i] == 1?(1<<i):0;
        }
        return res;
    }
    public static void main(String[] args) {
        singleNumber2 obj  = new singleNumber2();
        System.out.println(obj.singleNumber(List.of(1,2,3,2,3,1,3,2,1,4)));
    }
}
