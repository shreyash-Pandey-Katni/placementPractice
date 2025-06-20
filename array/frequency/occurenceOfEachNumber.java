import java.util.ArrayList;
import java.util.TreeMap;

public class occurenceOfEachNumber {
    public ArrayList<Integer> findOccurences(ArrayList<Integer> A) {
        TreeMap<Integer, Integer> resultMap = new TreeMap<>();
        for (int integer : A) {
            resultMap.put(integer, resultMap.getOrDefault(integer, 0) + 1);
        }
        ArrayList<Integer> result = new ArrayList<>(resultMap.values());
        return result;
    }

    public static void main(String[] args) {
        occurenceOfEachNumber obj = new occurenceOfEachNumber();
        ArrayList<Integer> input = new ArrayList<>();
        input.add(4);
        input.add(3);
        input.add(3);
        // input.add(3);
        // input.add(3);
        // input.add(3);
        ArrayList<Integer> result = obj.findOccurences(input);
        System.out.println(result);
    }
}
