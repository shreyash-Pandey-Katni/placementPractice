package math.numberEncoding;

import java.util.ArrayList;

public class rearrangeArray {
    public void arrange(ArrayList<Integer> a) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            a.set(i, a.get(i) + n * (a.get(a.get(i)) % n));
        }
        for (int i = 0; i < n; i++) {
            a.set(i, a.get(i) / n);
        }
    }

    public static void main(String[] args) {
        rearrangeArray rearranger = new rearrangeArray();
        ArrayList<Integer> arr = new ArrayList<>();
        arr.add(0);
        arr.add(2);
        arr.add(1);
        rearranger.arrange(arr);
        System.out.println("Rearranged Array: " + arr);
    }
}
