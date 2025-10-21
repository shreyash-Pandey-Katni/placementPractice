package string;

public class minimumParanthesis {
    public int solve(String A) {
        int balance = 0, additionOpenBracket = 0;
        int length = A.length();
        for (int i = 0; i < length; i++) {
            if (A.charAt(i) == '(') {
                balance++;
            } else{
                if (balance == 0) {
                    additionOpenBracket++;
                } else {
                    balance--;
                }
            }
        }
        return balance+additionOpenBracket;
    }
    public static void main(String[] args) {
        String A = ")(";
        minimumParanthesis obj = new minimumParanthesis();
        System.out.println(obj.solve(A));
    }
}
