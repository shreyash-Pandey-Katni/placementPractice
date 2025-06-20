import java.util.ArrayList;

public class rotateMatrix {
    public void rotate(ArrayList<ArrayList<Integer>> a) {
        int n = a.size();
        if (n == 1) {
            return;
        }
        int numberOfLayers = n / 2;
        for (int i = 0; i < numberOfLayers; i++) {
            for (int j = i; j < n - 1 - i; j++) {
                int temp = a.get(i).get(j);
                a.get(i).set(j, a.get(n - j - 1).get(i));
                a.get(n - j - 1).set(i,
                        a.get(n - 1 - i).get(n - 1 - j));
                a.get(n - i - 1).set(n - 1 - j,
                        a.get(j).get(n - i - 1));
                a.get(j).set(n - i - 1, temp);
            }
        }
    }

    public static void main(String[] args) {
        ArrayList<ArrayList<Integer>> matrix = new ArrayList<>();
        int numberOfElements = 6;
        for (int i = 0; i < numberOfElements; i++) {
            ArrayList<Integer> row = new ArrayList<>();
            for (int j = 0; j < numberOfElements; j++) {
                row.add(i * numberOfElements + j + 1);
            }
            matrix.add(row);
        }
        rotateMatrix rm = new rotateMatrix();
        rm.rotate(matrix);
        for (ArrayList<Integer> row : matrix) {
            System.out.println(row);
        }
    }
}