package bitsPlay;

public class reverseBits {
    public long reverse(long a) {
        long[] bitsArray = new long[32];
        long carry = 0;
        long bit;
        for(int i = 0;i<32;i++){
            bit = a>>i & 1;
            carry = carry | (bit<<(31-i));
        }
        return carry;
	}
    public static void main(String[] args) {
        reverseBits obj = new reverseBits();
        System.out.println(obj.reverse(3)); // Output: 3221225472
    }
}
