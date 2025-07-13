package math;

public class nextSmallestPalindrome {
    public String solve(String A) {
        int n = A.length();
        int i = 0;
        boolean isAll9s = true;
        for (char c : A.toCharArray()) {
            if (c != '9') {
                isAll9s = false;
                break;
            }
        }
        if (isAll9s) {
            StringBuilder sb = new StringBuilder();
            sb.append('1');
            for (int j = 0; j < n - 1; j++) {
                sb.append('0');
            }
            sb.append('1');
            return sb.toString();
        }
        // Increment number by 1
        int carry = 1;
        i = n - 1;
        while (i >= 0 && carry != 0) {
            int leastSignVal = A.charAt(i) - '0';
            int nextVal = leastSignVal + 1;
            carry = nextVal / 10;
            nextVal %= 10;
            A = A.substring(0, i) + (char) (nextVal + '0') + A.substring(i + 1);
            i--;
        }
        i = 0;

        StringBuilder res = new StringBuilder(A);
        n = res.length();
        while (i < n / 2) {
            char leastSignificantChar = A.charAt(n - i - 1);
            char mostSignificantChar = A.charAt(i);
            if (leastSignificantChar != mostSignificantChar) {
                res.setCharAt(n - i - 1, mostSignificantChar);
            }
            i++;
        }
        // Check if the palindrome is smaller than the original number
        boolean isSmaller = false;
        for (int j = 0; j < n; j++) {
            if (res.charAt(j) < A.charAt(j)) {
                isSmaller = true;
                break;
            } else if (res.charAt(j) > A.charAt(j)) {
                break;
            }
        }
        if (isSmaller) {
            int mid = n / 2;
            if (A.charAt(mid) == '9') {
                if (n % 2 == 0) {
                    int indexTill9 = mid - 1;
                    while (indexTill9 >= 0 && A.charAt(indexTill9) == '9') {
                        res.setCharAt(indexTill9, '0');
                        res.setCharAt(n - indexTill9 - 1, '0');
                        indexTill9--;
                    }
                    res.setCharAt(indexTill9, (char) (res.charAt(indexTill9) + 1));
                    res.setCharAt(n - indexTill9 - 1, (char) (res.charAt(n - indexTill9 - 1) + 1));
                } else {
                    int indexTill9 = mid;
                    while (indexTill9 >= 0 && A.charAt(indexTill9) == '9') {
                        res.setCharAt(indexTill9, '0');
                        res.setCharAt(n - indexTill9 - 1, '0');
                        indexTill9--;
                    }
                    res.setCharAt(indexTill9, (char) (res.charAt(indexTill9) + 1));
                    res.setCharAt(n - indexTill9 - 1, (char) (res.charAt(n - indexTill9 - 1) + 1));

                }
            } else {
                if (n % 2 == 0) {
                    StringBuilder strBldr = new StringBuilder(res.substring(0, mid));
                    strBldr.setCharAt(strBldr.length() - 1, (char) (strBldr.charAt(strBldr.length() - 1) + 1));
                    res = new StringBuilder();
                    res.append(strBldr);
                    res.append(strBldr.reverse());
                } else {
                    StringBuilder strBldr = new StringBuilder(res.substring(0, mid + 1));
                    strBldr.setCharAt(strBldr.length() - 1, (char) (strBldr.charAt(strBldr.length() - 1) + 1));
                    res = new StringBuilder();
                    res.append(strBldr);
                    res.append(strBldr.reverse().substring(1));
                }
            }
        }
        return res.toString();
    }

    public static void main(String[] args) {
        nextSmallestPalindrome obj = new nextSmallestPalindrome();
        String result = obj.solve("9651099683484992553337438088068198972282890781586124258626539246182119762952003918195325258677229419");
        System.out.println(result); // Output: "9651099683484992553337438088068198972282890781586124258626539246182119762952003918195325258677229419"
        System.out.println("isMatchingExpected: " + result.equals("9651099683484992553337438088068198972282890781586124258626539246182119762952003918195325258677229419"));
    }
}