import java.util.ArrayList;

public class maximumUnsortedSubArray {
    public ArrayList<Integer> subUnsort(ArrayList<Integer> A) {
        ArrayList<Integer> duplicateArray = new ArrayList<>();
        for (int i = 0; i < A.size(); i++) {
            duplicateArray.add(A.get(i));
        }
        duplicateArray.sort(Integer::compareTo);
        int start = -1, end = -1;
        for (int i = 0; i < A.size(); i++) {
            if (A.get(i) != duplicateArray.get(i) && start == -1) {
                start = i;
                break;
            }
        }
        for (int i = 0; i < A.size(); i++) {
            if (A.get(i) != duplicateArray.get(i)) {
                end = i;
            }
        }
        ArrayList<Integer> result = new ArrayList<>();
        if (start != -1) {
            result.add(start);
        }
        result.add(end);
        return result;
    }

    public static void main(String[] args) {
        maximumUnsortedSubArray obj = new maximumUnsortedSubArray();
        ArrayList<Integer> A = new ArrayList<>();
        A.add(1);
        A.add(3);
        A.add(2);
        A.add(4);
        A.add(5);
        ArrayList<Integer> result = obj.subUnsort(A);
        System.out.println(result); // Output: [1, 2, 3]
    }
}
