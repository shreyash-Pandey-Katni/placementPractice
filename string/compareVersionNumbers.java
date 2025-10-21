package string;

public class compareVersionNumbers {
    public int compareVersion(String A, String B) {
        String[] versionA = A.split("\\.");
        String[] versionB = B.split("\\.");

        int len = Math.max(versionA.length, versionB.length);
        
        for (int i = 0; i < len; i++) {
            String segmentA = i < versionA.length ? versionA[i] : "0";
            String segmentB = i < versionB.length ? versionB[i] : "0";
            int removeLeadingZerosA = 0, removeLeadingZerosB = 0;
            while (removeLeadingZerosA < segmentA.length() && segmentA.charAt(removeLeadingZerosA) == '0') {
                removeLeadingZerosA++;
            }
            while (removeLeadingZerosB < segmentB.length() && segmentB.charAt(removeLeadingZerosB) == '0') {
                removeLeadingZerosB++;
            }
            segmentA = segmentA.substring(removeLeadingZerosA);
            segmentB = segmentB.substring(removeLeadingZerosB);
            if (i == 0) {
                if (segmentA.length() > segmentB.length()) {
                    return 1;
                } else if (segmentA.length() < segmentB.length()) {
                    return -1;
                }
            }
            for (int j = 0; j < Math.max(segmentB.length(),segmentA.length()); j++) {
                if ((j < segmentA.length() ? segmentA.charAt(j) : '0') > (j < segmentB.length() ? segmentB.charAt(j) : '0')) {
                    return 1;
                } else if ((j < segmentA.length() ? segmentA.charAt(j) : '0') < (j < segmentB.length() ? segmentB.charAt(j) : '0')) {
                    return -1;
                }
            }
        }
        return 0;
    }

    public static void main(String[] args) {
        compareVersionNumbers comparer = new compareVersionNumbers();
        String version1 = "2";
        String version2 = "4";
        System.out.println("Comparing versions: " + version1 + " and " + version2);
        int result = comparer.compareVersion(version1, version2);
        System.out.println("Result: " + result); // Expected output: 0
    }
}
