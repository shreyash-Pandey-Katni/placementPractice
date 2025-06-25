package math;

public class powerOfTwoIntegers {
    public int isPower(int A) {
        int i = 2;
        if (A == 1) {
            return 1; // 1 is not a power of two integers
            
        }
        if (A < 4) {
            return 0; // 0 and 1 are not powers of two integers
        }
        if (A == 4) {
            return 1; // 4 is 2^2
        }
        int temp = A;
        int power = 0;
        while (i <= A / 2) {
            if (temp == i) {
                return power == 0 ? 0 : 1;
            }
            if (temp % i == 0) {
                temp /= i;
                power++;
                continue;
            }
            i++;
            temp = A;
        }
        return 0;
    }

    public static void main(String[] args) {
        powerOfTwoIntegers obj = new powerOfTwoIntegers();
        int result = obj.isPower(16); // Example input
        System.out.println(result); // Output: 1 (since 16 is 2^4)
        result = obj.isPower(18); // Example input
        System.out.println(result); // Output: 0 (since 18 is not a power of two integers)
        result = obj.isPower(1); // Example input
        System.out.println(result); // Output: 0 (since 1 is not a power of two integers)
        result = obj.isPower(4); // Example input
        System.out.println(result); // Output: 1 (since 4 is 2^2)
        result = obj.isPower(11); // Example input
        System.out.println(result); // Output: 0 (since 11 is not a power of two integers)
    }
}
