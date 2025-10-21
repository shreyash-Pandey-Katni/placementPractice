package bitsPlay;

public class divideIntegers {
    public int divide(int A, int B) {
        if ((A == Integer.MIN_VALUE && B == -1)) {
            return Integer.MAX_VALUE;
        } else if(B == 1) {
            return A;
        } else if(B == -1) {
            return -A;
        }
        boolean isNegative = (A<0 && B>0) || (A>0 && B<0);
        long a = Math.abs((long)A);
        long b = Math.abs((long)B);
        int res = 0;
        while (a>=b) {
            int x = 0;
            while ((a-(b<<1<<x))>=0) {
                x++;
            }
            res += 1<<x;
            a -= b<<x;
        }
        return isNegative?-1*res:res;
    }
    public static void main(String[] args) {
        divideIntegers obj = new divideIntegers();
        System.out.println(obj.divide(-2147483648,-10000000));
    }
}
