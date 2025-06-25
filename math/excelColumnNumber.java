package math;

public class excelColumnNumber {
    public int titleToNumber(String A) {
        int n = A.length();
        int i = n - 1;
        int result = 0;
        while (i >= 0) {
            result += (A.charAt(i) - 'A'+1) * Math.pow(26, n - 1 - i);
            i--;
        }
        return result;
    }

    public static void main(String[] args) {
        excelColumnNumber solution = new excelColumnNumber();
        String columnTitle = "AB";
        int columnNumber = solution.titleToNumber(columnTitle);
        System.out.println("The column number for " + columnTitle + " is: " + columnNumber);
    }
}
