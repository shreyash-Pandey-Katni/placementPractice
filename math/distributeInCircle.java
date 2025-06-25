package math;

public class distributeInCircle {
    public int solve(int A, int B, int C) {
        return (A + C - 1) % B;
    }

    public static void main(String[] args) {
        distributeInCircle circle = new distributeInCircle();
        System.out.println(circle.solve(5, 3, 2)); // Output: 1
        System.out.println(circle.solve(10, 4, 3)); // Output: 1
        System.out.println(circle.solve(7, 5, 2)); // Output: 4
        System.out.println(circle.solve(8, 6, 3)); // Output: 5
    }
}
