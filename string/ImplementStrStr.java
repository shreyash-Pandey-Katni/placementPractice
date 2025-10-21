package string;

public class ImplementStrStr {
    public int strStr(final String A, final String B) {
        if (A.isEmpty() || B.isEmpty()) {
            return -1;
        }

        int lengthA = A.length(), lengthB = B.length();

        for (int i = 0; i < lengthA; i++) {
            if (A.charAt(i) == B.charAt(0)) {
                int res = i;
                int k = i;
                for (int j = 0; j < lengthB; j++) {
                    if (k < lengthA && A.charAt(k) == B.charAt(j)) {
                        k++;
                    } else {
                        break;
                    }
                }
                if (k - res == lengthB) {
                    return res;
                }
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        // A : "bbaabbbbbaabbaabbbbbbabbbabaabbbabbabbbbababbbabbabaaababbbaabaaaba"
        // B : "babaaa"
        ImplementStrStr obj = new ImplementStrStr();
        String A = "bbaabbbbbaabbaabbbbbbabbbabaabbbabbabbbbababbbabbabaaababbbaabaaaba";
        String B = "babaaa";
        System.out.println(obj.strStr(A, B)); // Expected output: 7
    }
}
