package bitsPlay;

public class countTotalSetBits {
    int MOD = 1_000_000_007;
    public int solve(int A) {
        int res = 0;
        int i = 0;
        for (int j = 0; j < 32; j++) {
            long pow2 = 1L<<j;
            if(pow2>A) break;
            long completeGroups = (A+1)/(pow2*2);
            long remainder = (A+1)%(pow2*2);
            long setBitsAtPosition = completeGroups*pow2;
            if (remainder>pow2) {
                setBitsAtPosition+=remainder-pow2;
            }
            res += setBitsAtPosition%MOD;
            res %= MOD;
        }
        return res;
    }
    public static void main(String[] args) {
        countTotalSetBits obj  = new countTotalSetBits();
        System.out.println(obj.solve(3));
    }
}
