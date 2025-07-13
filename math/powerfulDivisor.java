package math;

import java.util.ArrayList;

public class powerfulDivisor {
    int[] map = new int[1000001];
    int[] divisorCount = new int[1000001];

   

    public ArrayList<Integer> powerfulDivisors(ArrayList<Integer> A) {
        int max = 0;
        for (Integer integer : A) {
            if (integer > max) {
                max = integer;
            }
        }

        for (int i = 1; i <= max; i++) {
            for (int j = i; j <= max; j += i) {
                divisorCount[j]++;
            }
            if (divisorCount[i] > 0 && (divisorCount[i] & (divisorCount[i] - 1)) == 0) {
                map[i] = map[i - 1] + 1;
            } else {
                map[i] = map[i - 1];
            }
        }

        ArrayList<Integer> result = new ArrayList<>();
        for (Integer integer : A) {
            result.add(map[integer]);
        }
        return result;
    }

    public static void main(String[] args) {
        powerfulDivisor pd = new powerfulDivisor();
        ArrayList<Integer> A = new ArrayList<>();
        A.add(2);
        A.add(3);
        A.add(4);
        A.add(5);
        A.add(1000000);
        ArrayList<Integer> result = pd.powerfulDivisors(A);
        System.out.println("Powerful Divisors: " + result);
    }
}
