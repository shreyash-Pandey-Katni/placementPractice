package backtracking;

public class modularExpression {
    private long pow(long A, int B, int C) {
        if (B == 0) {
            return 1;
        }
        long half = pow(A, B/2, C);
        if (B%2 ==0) {
            return half*half%C;
        } else {
            return pow(A, B-1, C)* A%C;
        }
        
    }
    public int Mod(int A, int B, int C) {
        long multiply = pow(A, B, C);
        if (multiply<0) {
            multiply = multiply + (Math.abs(multiply/C)+1)*C;
        }
        return (int) (multiply%C);
    }
    public static void main(String[] args) {
        int A = 71045970, B = 41535484, C = 64735492;
        modularExpression obj = new modularExpression();
        System.out.println(obj.Mod(A, B, C)); // Output: 19
    }
}
