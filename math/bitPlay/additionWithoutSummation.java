package math.bitPlay;

public class additionWithoutSummation {
    public int addNumbers(int A, int B) {
        while (B != 0) {
            int carry = A & B;
            A = A ^ B;
            B = carry << 1;
        }
        return A;
    }
    public static void main(String[] args) {
        additionWithoutSummation adder = new additionWithoutSummation();
        int A = 15;
        int B = 27;
        int result = adder.addNumbers(A, B);
        System.out.println("The sum of " + A + " and " + B + " is: " + result); // Output should be 42
    }
}
