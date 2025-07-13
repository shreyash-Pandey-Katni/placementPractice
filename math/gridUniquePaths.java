package math;

public class gridUniquePaths {
    public int uniquePaths(int A, int B) {
        int[] prevArrayList = new int[B];
        for (int i = 0; i < B; i++) {
            prevArrayList[i] = 1;
        }
        for (int i = 1; i < A; i++) {
            for (int j = 1; j < B; j++) {
                prevArrayList[j] += prevArrayList[j-1];
            }
        }
        return prevArrayList[B-1];

    }
    public static void main(String[] args) {
        gridUniquePaths g = new gridUniquePaths();
        System.out.println(g.uniquePaths(3, 7));
    }
}
