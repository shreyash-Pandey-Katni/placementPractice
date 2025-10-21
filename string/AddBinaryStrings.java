package string;

public class AddBinaryStrings {
    public String addBinary(String A, String B) {
        int lengthA = A.length(), lengthB = B.length();
        int i = 0;
        int carry = 0;
        StringBuilder stringBuilder = new StringBuilder();
        while (i<lengthA && i<lengthB) {
            int tempA = A.charAt(lengthA-1-i) - '0' , tempB = B.charAt(lengthB - 1 -i) - '0';
            stringBuilder.append(String.valueOf((tempA+tempB + carry)%2));
            carry = (tempA + tempB + carry)/2;
            i++;
        }
        while (i<lengthA) {
            int tempA = A.charAt(lengthA-1-i) - '0';
            stringBuilder.append(String.valueOf((tempA + carry)%2));
            carry = (tempA + carry)/2;
            i++;
        }
        while (i<lengthB) {
            int tempB = B.charAt(lengthB-1-i) - '0';
            stringBuilder.append(String.valueOf((tempB + carry)%2));
            carry = (tempB + carry)/2;
            i++;
        }
        if (carry == 1) {
            return "1" + stringBuilder.reverse().toString();
        }
        return stringBuilder.reverse().toString();
    }
    public static void main(String[] args) {
        String A = "111";
        String B = "111";
        AddBinaryStrings obj = new AddBinaryStrings();
        System.out.println(obj.addBinary(A, B)); // Output: 1110
    }
}
