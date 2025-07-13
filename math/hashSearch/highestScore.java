package math.hashSearch;

import java.util.ArrayList;
import java.util.HashMap;

public class highestScore {
    public int highestScore(ArrayList<ArrayList<String>> A) {
        int n = A.size();
        HashMap<String, long[]> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String name = A.get(i).get(0);
            long value = Long.parseLong(A.get(i).get(1));
            if (map.containsKey(name)) {
                map.get(name)[0] += value;
                map.get(name)[1]++;
            } else {
                long[] temp = new long[2];
                temp[0] = value;
                temp[1] = 1L;
                map.put(name, temp);
            }
        }
        int max = Integer.MIN_VALUE;
        for (String key : map.keySet()) {
            max = (int) Math.max(max, map.get(key)[0] / map.get(key)[1]);
        }
        return max;
    }
    public static void main(String[] args) {
        highestScore hs = new highestScore();
        ArrayList<ArrayList<String>> A = new ArrayList<>();
        ArrayList<String> entry1 = new ArrayList<>();
        entry1.add("Alice");
        entry1.add("100");
        A.add(entry1);
        
        ArrayList<String> entry2 = new ArrayList<>();
        entry2.add("Bob");
        entry2.add("200");
        A.add(entry2);
        
        ArrayList<String> entry3 = new ArrayList<>();
        entry3.add("Alice");
        entry3.add("300");
        A.add(entry3);
        
        System.out.println(hs.highestScore(A)); // Output should be 200
    }
}
