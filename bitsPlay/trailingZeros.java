package bitsPlay;

public class trailingZeros {
    public int solve(int A) {
        int carry = A;
        int res=0;
        while (carry != 0) {
            if (carry%2 == 1)return res;
            else res++;
            carry /=2;
        }
        return res;
    }
    public static void main(String[] args) {
        trailingZeros obj = new trailingZeros();
        // System.out.println(obj.solve(8)); // Output: 3
        // System.out.println(obj.solve(12)); // Output: 2
        // System.out.println(obj.solve(7)); // Output: 0
        System.out.println(obj.solve(18)); // Output: 0
    }
}
