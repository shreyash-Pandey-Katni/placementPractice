import java.util.ArrayList;
import java.util.Comparator;

public class waveArray {
    public ArrayList<Integer> wave(ArrayList<Integer> A) {

        int n = A.size();
        if (n == 1) {
            return A;
        }
        A.sort(new Comparator<Integer>() {
            @Override
            public int compare(Integer arg0, Integer arg1) {
                return Integer.compare(arg0, arg1);
            }
        });
        ArrayList<Integer> result = new ArrayList<Integer>(n);
        for (Integer integer : A) {
            result.add(0);
        }
        result.set(0, A.get(1));
        result.set(1, A.get(0));
        for (int index = 2; index < n; index++) {
            if (index % 2 == 0 && index + 1 < n) {
                result.set(index + 1, A.get(index));
            } else if(index%2 == 1) {
                result.set(index - 1, A.get(index));
            } else {
                result.set(index, A.get(index));
            }

        }
        return result;
    }

    public static void main(String[] args) {
        waveArray wa = new waveArray();
        ArrayList<Integer> input = new ArrayList<>();
        input.add(1);
        input.add(2);
        input.add(3);
        input.add(4);
        input.add(5);
        ArrayList<Integer> result = wa.wave(input);
        System.out.println(result); // Output: [1, 3, 2, 5, 4]
    }
}
