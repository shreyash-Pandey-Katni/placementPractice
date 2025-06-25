package math;

import java.util.ArrayList;

public class fizzBuzz {
    public ArrayList<String> fizzBuzz(int A) {
        ArrayList<String> result = new ArrayList<>(A);
        for (int i = 0; i < A; i++) {
            int num = i + 1;
            if ((num) % 3 == 0 && (num) % 5 == 0) {
                result.add("FizzBuzz");
            } else if (num % 3 == 0) {
                result.add("Fizz");
            } else if (num % 5 == 0) {
                result.add("Buzz");
            } else {
                result.add("" + num);
            }
        }
        return result;
    }

    public static void main(String[] args) {
        fizzBuzz fb = new fizzBuzz();
        int A = 15; // Example input
        ArrayList<String> result = fb.fizzBuzz(A);
        System.out.println("FizzBuzz sequence for " + A + ": " + result);
    }
}
