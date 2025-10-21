package string;

import java.util.ArrayList;

public class deserialize {
    public ArrayList<String> deserialize(String A) {
        String[] stringArray = A.split("~");
        ArrayList<String> res = new ArrayList<>();
        int n = stringArray.length;
        for (int i = 0; i < n; i++) {
            res.add(stringArray[i].replaceAll("\\d+", ""));
        }
        return res;
    }
}
