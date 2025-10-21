package bitsPlay;

public class palindromicBinarRepresentation {

    private int generateIthPalindromeOfLengthK(int length, int index){
        if (length == 1) {
            return 1;
        }
        int prefixLength = (length+1)/2;
        int smallestValueOfPrefixLength = (1<<(prefixLength-1))+(index-1);
        
        int result = smallestValueOfPrefixLength, temp = smallestValueOfPrefixLength;
        
        if (length%2==1) {
            temp = temp >>1;
        }
        while (temp>0) {
            result = (result <<1) | (temp&1);
            temp = temp >>1;
        }

        return result;
    }

    public int solve(int A) {
        int count = 0;
        int length = 1;
        while (true) {
            int palindromesInCurrentLength = 1 << ((length-1)/2);
            if (count+palindromesInCurrentLength >= A) {
                return generateIthPalindromeOfLengthK(length, A-count);
            }
            count += palindromesInCurrentLength;
            length++;
        }
    }
    public static void main(String[] args) {
        palindromicBinarRepresentation obj = new palindromicBinarRepresentation();
        obj.solve(5);
    }
}
