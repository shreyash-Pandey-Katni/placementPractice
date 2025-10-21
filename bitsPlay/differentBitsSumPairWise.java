package bitsPlay;

import java.util.ArrayList;

public class differentBitsSumPairWise {
    int MOD = 1_000_000_007;
    private long numberOfDifferentBits(int a, int b){
        long res = 0;
        for(int i = 0;i<32;i++){
            if (a>>i == 0 && b>>i == 0) {
                break;
            }
            res += ((a>>i)&1) ^ ((b>>i)&1);
        }
        return res;
    }
    public int cntBits(ArrayList<Integer> A) {
        long res = 0, n = A.size();
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                res += numberOfDifferentBits(A.get(i), A.get(j));        
            }
        }
        return (int)(res*2 % MOD);
    }
    public int cntBitsImproved(ArrayList<Integer> A){
        int n = A.size();
        long result = 0;
        for (int i = 0; i < 32; i++) {
            long countZero = 0;
            long countOne = 0;
            for (Integer integer : A) {
                if ((integer >> i & 1) == 1) {
                    countOne++;
                } else {
                    countZero++;
                }
                countOne%=MOD;
                countZero%=MOD;
            }
            result = (result+((countOne*countZero*2)%MOD))%MOD;
        }
        return (int) result%MOD;
    }
    public static void main(String[] args) {
        differentBitsSumPairWise obj = new differentBitsSumPairWise();
        ArrayList<Integer> A = new ArrayList<>();
        A.add(1);
        A.add(3);
        A.add(5);
        System.out.println(obj.cntBits(A)); // Output: 8
    }
}
