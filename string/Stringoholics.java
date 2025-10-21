package string;

import java.io.BufferedReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

import math.primeSum;

public class Stringoholics {
    int MOD = 1_000_000_007;
    // private long gcd(long a, long b) {
    //     if (b == 0) return a;
    //     return gcd(b, a % b);
    // }
    
    

    // private long lcm(long a, long b) {
    //     long g = gcd(a, b);
    //     // To avoid overflow: a/g * b instead of (a*b)/g
    //     // But we still need to handle potential overflow in a/g * b
    //     long result = a / g;
    //     // Check if multiplication will overflow
    //     if (result > Long.MAX_VALUE / b) {
    //         // If overflow would occur, we need a different approach
    //         // Use the fact that we only need result % MOD
    //         return mulMod(result, b, MOD);
    //     }
    //     return result * b;
    // }
    
    // // Multiply two numbers under modulo to avoid overflow
    // private long mulMod(long a, long b, long mod) {
    //     long result = 0;
    //     a %= mod;
    //     b %= mod;
        
    //     while (b > 0) {
    //         if ((b & 1) == 1) {
    //             result = (result + a) % mod;
    //         }
    //         a = (a * 2) % mod;
    //         b >>= 1;
    //     }
    //     return result;
    // }
    // public long cycleLength(int n){
    //     if (n%2==0) return n;
    //     return (2L*n);
    // }
    private long power(long base, long exp) {
        long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
    // private String rotateString(String A, int k){
    //     StringBuilder stringBuilder = new StringBuilder();
    //     int length = A.length();
    //     k = k*(k+1)/2;
    //     for (int i = 0; i < length; i++) {
    //         stringBuilder.append(A.charAt((i+k)%length));
    //     }
    //     return stringBuilder.toString();
    // }
    private long smallestString(String A){
        int length = A.length();
        int len = 0;
        int[] lps = new int[length];
        lps[0] = 0;
        int i =1;
        while (i<length) {
            if (A.charAt(i) == A.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if (len != 0) {
                    len = lps[len-1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        long t1 = lps[length-1];
        long t2 = length-t1;
        if (t1<t2) {
            return length;
        } else if(t1%t2 != 0) return length;
        else return t2;
    }
    public int solve(ArrayList<String> A) {
        HashMap<Long, Long> powerHashMap = new HashMap<>();
        int n = A.size();
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) {
            long length = smallestString(A.get(i));
            long k = 1;
            while (true) {
                long changes=  (k*(k+1))/2;
                if (changes%length == 0) {
                    arr[i] = k;
                    break;
                }
                k++;
            }
        }
        for (long cycle : arr) {
            long num = cycle;
            // FIX 1: Efficiently loop up to the square root
            for (long j = 2; j * j <= num; j++) {
                if (num % j == 0) {
                    long count = 0;
                    while (num % j == 0) {
                        num /= j;
                        count++;
                    }
                    powerHashMap.put(j, Math.max(powerHashMap.getOrDefault(j, 0L), count));
                }
            }
            // FIX 2: Correctly handle the last remaining prime factor
            if (num > 1) {
                powerHashMap.put(num, Math.max(powerHashMap.getOrDefault(num, 0L), 1L));
            }
        }
        long finalLcmMod = 1;
        for (Map.Entry<Long, Long> entry : powerHashMap.entrySet()) {
            long prime = entry.getKey();
            long maxPower = entry.getValue();
            long term = power(prime, maxPower) %MOD;
            finalLcmMod = (finalLcmMod * term) % MOD;
        }
        // for (long l : arr) {
        //     finalLcmMod = lcm(finalLcmMod, l);
        // }
        // for (int i = 0; i < n; i++) {
        //     for (int j = i+1; j < arr.length && arr[i] != 1; j++) {
        //         arr[j] = arr[j]/gcd(arr[i], arr[j]);
        //     }
        //     finalLcmMod = 1L*(finalLcmMod%MOD*(arr[i])%MOD)%MOD;
        // }
        return (int)(finalLcmMod % MOD);
    }
    public static void main(String[] args) {
        ArrayList<String> A = new ArrayList<>();
        // Read input strings from file, "input.txt", which has first word as number of strings followed by strings. Use space as a delimiter.
        try (BufferedReader br = new BufferedReader(new java.io.FileReader("/home/shreyash/VSCode/placementPractice/string/input.txt"))) {
            String line = br.readLine();
            String[] splits = line.trim().split(" ");
            int n = Integer.parseInt(splits[0]);
            for (int i = 1; i <= n; i++) {
                A.add(splits[i]);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

        Stringoholics obj = new Stringoholics();
        System.out.println(obj.solve(A));
    }
}