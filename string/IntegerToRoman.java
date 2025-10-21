package string;

public class IntegerToRoman {
    public String intToRoman(int A) {
        int[] numbers = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        String[] values = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        StringBuilder stringBuilder = new StringBuilder();
        int i = 0;
        while (A>0) {
            if (A>=numbers[i]) {
                A -= numbers[i];
                stringBuilder.append(values[i]);
            } else i++;
        }
        return stringBuilder.toString();
    }
    public static void main(String[] args) {
        int A = 3;
        IntegerToRoman obj = new IntegerToRoman();
        System.out.println(obj.intToRoman(A));
    }
}
