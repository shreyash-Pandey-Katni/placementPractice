package string;

import java.math.BigInteger;

public class powerOf2 {
    private String divideBy2(String A){
        StringBuilder stringBuilder = new StringBuilder();
        int carry = 0;
        for (int i = 0; i < A.length(); i++) {
            int digit = A.charAt(i) - '0';
            int currentValue = carry*10+digit;
            stringBuilder.append(currentValue/2);
            carry = currentValue%2;
        }
        int firstNonZero = 0;
        while (firstNonZero < stringBuilder.length() - 1 && stringBuilder.charAt(firstNonZero) == '0') {
            firstNonZero++;
        }
        return stringBuilder.substring(firstNonZero);
    }
    public int power(String A) {
        if (A.equals("1")) {
            return 0;
        }

        while (!A.equals("0") && !A.equals("1")) {
            if ((A.charAt(A.length() - 1) - '0') % 2 != 0) {
                return 0;
            }
            A = divideBy2(A);
        }

        return A.equals("1")? 1 : 0;
    }
    public static void main(String[] args) {
        String A = "16";
        powerOf2 obj = new powerOf2();
        System.out.println(obj.power(A)); // Output: 1
    }
}
