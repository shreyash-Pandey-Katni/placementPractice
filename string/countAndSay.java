package string;

public class countAndSay {
    public String countAndSay(int A) {
        int i = 1;
        String currentString = "1";
        while (i<A) {
            StringBuilder stringBuilder = new StringBuilder();
            int count = 1;
            char lastChar = currentString.charAt(0);
            for(int j = 1;j<currentString.length();j++){
                if (lastChar == currentString.charAt(j)) {
                    count++;
                } else {
                    stringBuilder.append(String.valueOf(count));
                    stringBuilder.append(lastChar);
                    lastChar = currentString.charAt(j);
                    count = 1;
                }
            }
            stringBuilder.append(String.valueOf(count));
            stringBuilder.append(lastChar);
            currentString = stringBuilder.toString();
            i++;
        }
        return currentString;
    }
    public static void main(String[] args) {
        
    }
}
