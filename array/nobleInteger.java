import java.util.ArrayList;
import java.util.TreeMap;

public class nobleInteger {
    public int solve(ArrayList<Integer> A) {
        TreeMap<Integer, Integer> map = new TreeMap<>();
        for (Integer integer : A) {
            map.put(integer, map.getOrDefault(integer, 0)+1);
        }
        int size = A.size();
        int count = 0;
        for (Integer integer : map.keySet()) {
            if (size - map.get(integer) - count == integer) {
                return 1;
            }
            else {
                count += map.get(integer);
            }
        }
        return -1;
    }
    public static void main(String[] args) {
        nobleInteger obj = new nobleInteger();
        ArrayList<Integer> A = new ArrayList<>();
        A.add(3);
        A.add(2);
        A.add(1);
        A.add(3);
        System.out.println(obj.solve(A)); // Output: 1
    }
}