package string;

import java.util.ArrayList;

public class prettyJson {
    private StringBuilder appendIndentation(StringBuilder sb, int indentation) {
        for (int j = 0; j < indentation; j++) {
            sb.append("\t");
        }
        return sb;
    }

    public ArrayList<String> prettyJSON(String A) {
        int indentation = 0;
        ArrayList<String> res = new ArrayList<>();
        StringBuilder stringBuilder = new StringBuilder();
        for (int i = 0; i < A.length(); i++) {
            char character = A.charAt(i);
            if (character == ',') {
                if (stringBuilder.length() == 0) {
                    stringBuilder = appendIndentation(stringBuilder, indentation);
                }
                stringBuilder.append(character);
                res.add(stringBuilder.toString());
                stringBuilder = new StringBuilder();
                stringBuilder = appendIndentation(stringBuilder, indentation);
            } else if (character == '[' || character == '{') {
                if (stringBuilder.toString().trim().length() > 0) {
                    res.add(stringBuilder.toString());
                    stringBuilder = new StringBuilder();
                    stringBuilder = appendIndentation(stringBuilder, indentation);
                }
                stringBuilder.append(character);
                res.add(stringBuilder.toString());
                stringBuilder = new StringBuilder();
                indentation++;
                stringBuilder = appendIndentation(stringBuilder, indentation);
            } else if (character == ']' || character == '}') {
                if (stringBuilder.length() != 0) {
                    res.add(stringBuilder.toString());
                }
                indentation--;
                StringBuilder cloStringBuilder = new StringBuilder();
                cloStringBuilder = appendIndentation(cloStringBuilder, indentation);
                cloStringBuilder.append(character);
                if (i + 1 < A.length() && A.charAt(i + 1) == ',') {
                    cloStringBuilder.append(',');
                    i++;
                    stringBuilder = appendIndentation(new StringBuilder(), indentation);
                } else {
                    stringBuilder = new StringBuilder();
                }
                res.add(cloStringBuilder.toString());
                // stringBuilder = appendIndentation(new StringBuilder(), indentation);
                // stringBuilder.append(character);
                // res.add(stringBuilder.toString());
                // stringBuilder = appendIndentation(new StringBuilder(), indentation);
            } else if (character == ':') {
                stringBuilder.append(character);
                if (i + 1 < A.length() && (A.charAt(i + 1) == '{' || A.charAt(i + 1) == '[')
                        && stringBuilder.toString().trim().length() > 0) {
                    res.add(stringBuilder.toString());
                    stringBuilder = new StringBuilder();
                    stringBuilder = appendIndentation(stringBuilder, indentation);
                }
            } else {
                if (stringBuilder.length() == 0) {
                    stringBuilder = appendIndentation(stringBuilder, indentation);
                }
                stringBuilder.append(character);
            }
        }
        if (stringBuilder.length() == 0) {
            return res;
        }
        res.add(stringBuilder.toString());
        return res;
    }

    public static void main(String[] args) {
        prettyJson pj = new prettyJson();
        // A :
        // {"attributes":[{"nm":"ACCOUNT","lv":[{"v":{"Id":null,"State":null},"vt":"java.util.Map","cn":1}],"vt":"java.util.Map","status":"SUCCESS","lmd":13585},{"nm":"PROFILE","lv":[{"v":{"Party":null,"Ads":null},"vt":"java.util.Map","cn":2}],"vt":"java.util.Map","status":"SUCCESS","lmd":41962}]}
        String A = "{\"attributes\":[{\"nm\":\"ACCOUNT\",\"lv\":[{\"v\":{\"Id\":null,\"State\":null},\"vt\":\"java.util.Map\",\"cn\":1}],\"vt\":\"java.util.Map\",\"status\":\"SUCCESS\",\"lmd\":13585},{\"nm\":\"PROFILE\",\"lv\":[{\"v\":{\"Party\":null,\"Ads\":null},\"vt\":\"java.util.Map\",\"cn\":2}],\"vt\":\"java.util.Map\",\"status\":\"SUCCESS\",\"lmd\":41962}]}";
        ArrayList<String> result = pj.prettyJSON(A);
        for (String line : result) {
            System.out.println(line);
        }
    }
}
