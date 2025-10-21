package string;

public class zigZagString {
    public String convert(String A, int B) {
        if (B <= 1 || A.length() <= B) return A;
        StringBuilder[] rows = new StringBuilder[B];
        for (int i = 0; i < B; i++) {
            rows[i] = new StringBuilder();
        }
        int n = A.length();
        int row = 0;
        boolean isMovingDownward = false;
        for (int i = 0; i < n; i++) {
            rows[row].append(A.charAt(i));
            if (!isMovingDownward && row == 0) {
                isMovingDownward = true;
            } else if (isMovingDownward && row == rows.length - 1) {
                isMovingDownward = false;
            }
            if (isMovingDownward) {
                row++;
            } else {
                row--;
            }
        }
        StringBuilder result = new StringBuilder();
        for (StringBuilder r : rows) {
            result.append(r);
        }
        return result.toString();
    }
    public static void main(String[] args) {
        String test1 = "PAYPALISHIRING";
        int numRows1 = 1;
        zigZagString obj = new zigZagString();
        System.out.println("ZigZag conversion of '" + test1 + "' with "+ numRows1 + " rows: " + obj.convert(test1, numRows1)); // Expected: "PAHNAPLSIIGYIR"
    }
}
