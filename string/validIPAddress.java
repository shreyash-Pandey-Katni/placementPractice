package string;

import java.util.ArrayList;

public class validIPAddress {
    private boolean isValidPart(String A){
        if (A == null || A.isEmpty()) {
            return false;
        }
        int n = A.length();
        if (A.charAt(0) == '0' && n != 1) {
            return false;
        }
        if (Integer.parseInt(A) <0 || Integer.parseInt(A) >255) {
            return false;
        }
        return true;
    }
    private void combinations(ArrayList<String> results,String currentIp, String remainingString, int partsCount) {
        if (partsCount == 4) {
            if (remainingString.isEmpty()) {
                results.add(currentIp.substring(0, currentIp.length() - 1));
            }
            return;
        }
        for (int i = 1; i < 4 && i <= remainingString.length(); i++) {
            String part = remainingString.substring(0, i);
            if (isValidPart(part)) {
                combinations(results, currentIp + part + ".", remainingString.substring(i), partsCount + 1);
            }
        }
    }
    public ArrayList<String> restoreIpAddresses(String A) {
        if (A.length() < 4 || A.length() > 12) {
            return new ArrayList<>();
        }
        ArrayList<String> result = new ArrayList<>();
        combinations(result, "", A, 0);
        return result;
    }
    public static void main(String[] args) {
        validIPAddress obj = new validIPAddress();
        String A = "25525511135";
        ArrayList<String> result = obj.restoreIpAddresses(A);
        System.out.println("Possible valid IP addresses for input " + A + " are:");
        for (String ip : result) {
            System.out.println(ip);
        }
    }
}
