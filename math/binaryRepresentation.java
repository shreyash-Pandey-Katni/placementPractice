package math;

public class binaryRepresentation {
    public String findDigitsInBinary(int A) {
        if (A == 0) {
            return "0";
        }
        StringBuilder binary = new StringBuilder();
        while (A > 0) {
            binary.insert(0, A % 2);
            A /= 2;
        }
        return binary.toString();
    }
}
