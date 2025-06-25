package math;

public class totalMovesForBishop {
    public int solve(int A, int B) {
        int oneMove = Math.min(8 - A, 8 - B);
        int secondMove = Math.min(A - 1, B - 1);
        int thirdMove = Math.min(8 - A, B - 1);
        int fourthMove = Math.min(A - 1, 8 - B);
        return oneMove + secondMove + thirdMove + fourthMove;
    }
    public static void main(String[] args) {
        totalMovesForBishop bishop = new totalMovesForBishop();
        System.out.println(bishop.solve(4, 4)); // Output: 14
        System.out.println(bishop.solve(1, 1)); // Output: 7
        System.out.println(bishop.solve(8, 8)); // Output: 7
        System.out.println(bishop.solve(3, 5)); // Output: 10
    }
}
