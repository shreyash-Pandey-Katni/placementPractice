package string;

public class multiplyString {
    public String multiply(String A, String B) {
        int lengthA = A.length(), lengthB = B.length();
        int[] res = new int[lengthA + lengthB];
        int carry = 0, sum = 0;
        for (int i = lengthB - 1; i >= 0; i--) {
            carry = 0;
            for (int j = lengthA - 1; j >= 0; j--) {
                sum = (A.charAt(j) - '0') * (B.charAt(i) - '0') + carry + res[i + j + 1];
                carry = sum / 10;
                res[j + i + 1] = sum % 10;
            }
            if (carry != 0) {
                res[i] = carry;
            }
        }
        int firstNonZero = 0;
        while (firstNonZero<res.length && res[firstNonZero] == 0) {
            firstNonZero++;
        }
        StringBuilder stringBuilder = new StringBuilder();
        for (int i : res) {
            stringBuilder.append(String.valueOf(i));
        }
        return firstNonZero==res.length?"0":stringBuilder.substring(firstNonZero).toString();
    }

    public static void main(String[] args) {
        String A = "31243242535342";
        String B = "0";
        multiplyString obj = new multiplyString();
        System.out.println(obj.multiply(A, B)); // Output: 56088
    }
}
