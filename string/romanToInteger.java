package string;

import java.util.HashMap;

public class romanToInteger {
    public int romanToInt(String A) {
        String[] values = {"CM","M", "CD","D",  "XC","C", "XL","L", "IX", "X", "IV","V", "I"};
        HashMap<String, Integer> map = new HashMap<>();
        map.put("M", 1000);
        map.put("CM", 900);
        map.put("D", 500);
        map.put("CD", 400);
        map.put("C", 100);
        map.put("XC", 90);
        map.put("L", 50);
        map.put("XL", 40);
        map.put("X", 10);
        map.put("IX", 9);
        map.put("V", 5);
        map.put("IV", 4);
        map.put("I", 1);

        int n = A.length();
        int i = 0;
        int res = 0;
        int valueIndex = 0;
        while (i<n) {
            if (n-i == 1) {
                res += map.get(A.substring(i));
                break;
            }
            if (map.containsKey(A.substring(i, i+2))) {
                res += map.get(A.substring(i, i+2));
                i += 2;
            } else{
                res += map.get(A.substring(i, i+1));
                i++;
            }
        }
        return res;
    }
    public static void main(String[] args) {
        romanToInteger obj = new romanToInteger();
        System.out.println(obj.romanToInt("MCMXCIV")); // 1994
        System.out.println(obj.romanToInt("LVIII")); // 58
    }
}
