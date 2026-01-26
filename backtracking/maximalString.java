package backtracking;

public class maximalString {
    private String maxString = "";

    private void backtrack(char[] current, int index, int swapsLeft){
    
        String currentString = new String(current);

        if (maxString.compareTo(currentString) < 0) {
            maxString = currentString;
        }

        if (swapsLeft == 0 || index >= current.length){
            return;
        }
        for (int i = index+1; i < current.length; i++) {
            if (current[i] > current[index]) {
                // Swap
                char temp = current[index];
                current[index] = current[i];
                current[i] = temp;

                backtrack(current, index + 1, swapsLeft - 1);

                // Backtrack (swap back)
                temp = current[index];
                current[index] = current[i];
                current[i] = temp;
            }
        }
        backtrack(current, index + 1, swapsLeft);
    }
    public String solve(String A, int B) {
        maxString = "";
        char[] current = A.toCharArray();
        backtrack(current, 0, B);
        return maxString;
    }
    public static void main(String[] args) {
        maximalString ms = new maximalString();
        String result = ms.solve("129814999", 4);
        System.out.println(result); // Expected output: "542"
    }
}
