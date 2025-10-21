package bitsPlay;

import java.util.List;

public class singleNumber {
    public int singleNumber(final List<Integer> A) {
        int xor = 0;
        for (Integer integer : A) {
            xor = xor ^integer;
        }
        return xor;
    }
}
