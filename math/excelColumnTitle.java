package math;

public class excelColumnTitle {
    public String convertToTitle(int A) {
        StringBuilder stringBuilder = new StringBuilder();
        int i = 0;
        while (A > 0) {
            i = A % 26;
            if (i == 0) {
                i = 26; // Adjust for the case where A is a multiple of 26
                A--; // Decrement A to handle the zero case correctly
            }
            stringBuilder.append((char) (i + 'A' - 1));
            A /= 26;
        }
        stringBuilder.reverse();
        return stringBuilder.toString();
    }

    public static void main(String[] args) {
        excelColumnTitle solution = new excelColumnTitle();
        int columnNumber = 980089; // Example input
        String columnTitle = solution.convertToTitle(columnNumber);
        System.out.println("The column title for " + columnNumber + " is: " + columnTitle);
        columnNumber = 52; // Example input
        columnTitle = solution.convertToTitle(columnNumber);
        System.out.println("The column title for " + columnNumber + " is: " + columnTitle);
        columnNumber = 943566; // Example input
        columnTitle = solution.convertToTitle(columnNumber);
        System.out.println("The column title for " + columnNumber + " is: " + columnTitle);
    }
}
