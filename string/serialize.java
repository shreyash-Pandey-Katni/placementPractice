package string;

import java.util.ArrayList;

public class serialize {
    public String serialize(ArrayList<String> A) {
        StringBuilder stringBuilder = new StringBuilder();
        int n = A.size();
        for (int i = 0; i < n; i++) {
            stringBuilder.append(A.get(i));
            stringBuilder.append(String.valueOf(A.get(i).length()));
            stringBuilder.append("~");
        }
        return stringBuilder.toString();
    }
}
