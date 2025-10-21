package string;

public class salutes {
    public Long countSalutes(String A) {
        int n = A.length();
        long totalSalutes = 0, rightMoversCount = 0;
        for (int i = 0; i < n; i++) {
            if (A.charAt(i) == '>') rightMoversCount++;
            else totalSalutes += rightMoversCount;
        }
        return totalSalutes;
    }
}
