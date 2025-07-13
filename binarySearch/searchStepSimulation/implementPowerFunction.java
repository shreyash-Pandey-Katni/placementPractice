package binarySearch.searchStepSimulation;

public class implementPowerFunction {

    private long pow(int x, int n) {
        long res = x;
        while (n > 1) {
            res *= res;
            n /= 2;
        }
        return res;
    }

    public int pow(int x, int n, int d) {
        if (n == 0)
            return 1 % d;
        if (x == 0)
            return 0;
        long res = 1, base = x % d;
        if (base < 0)
            base += d;
        while (n > 0) {
            if (n % 2 == 1)
                res = (res * base) % d;
            base = (base * base) % d;
            n /= 2;
        }
        return (int) res;
    }

    public static void main(String[] args) {
        // A : -1
        // B : 1
        // C : 20
        implementPowerFunction obj = new implementPowerFunction();
        int A = -1, B = 1, C = 20;
        int result = obj.pow(A, B, C);
        System.out.println("The result of " + A + "^" + B + " % " + C + " is: " + result);
    }
}
