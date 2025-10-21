package bitsPlay;

public class numberOf1Bit {
    public int numSetBits(long a) {
        long carry = a;
        int res=0;
        while (carry != 0) {
            if (carry%2 == 1) res++;
            carry /=2;
        }
        return res;
	}
}
