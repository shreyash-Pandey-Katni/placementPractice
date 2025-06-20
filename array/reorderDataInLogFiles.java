import java.util.ArrayList;
import java.util.TreeMap;

public class reorderDataInLogFiles {
    public ArrayList<String> reorderLogs(ArrayList<String> A) {
        TreeMap<String, ArrayList<String>> letterLogs = new TreeMap<>();
        ArrayList<String> digitLogs = new ArrayList<>();
        for (String log : A) {
            String[] parts = log.split("-", 2);
            String identifier = parts[0];
            String content = parts[1];

            if (Character.isDigit(content.charAt(0))) {
                digitLogs.add(log);
            } else {
                letterLogs.putIfAbsent(content, new ArrayList<>());
                letterLogs.get(content).add(identifier + "-" + content);
            }
        }
        ArrayList<String> result = new ArrayList<>();
        // Add letter logs sorted by content and identifier
        for (String content : letterLogs.keySet()) {
            ArrayList<String> identifiers = letterLogs.get(content);
            identifiers.sort(String::compareTo); // Sort by identifier
            result.addAll(identifiers);
        }
        // Add digit logs at the end
        result.addAll(digitLogs);
        return result;
    }
    public static void main(String[] args) {
        reorderDataInLogFiles obj = new reorderDataInLogFiles();
        // A : [ "qv4-tbojcv-yd", "uh9-lmtdpiunu", "ta9-5-3-5-5-1", "hn2-yawf-jw-zkw", "nc7-hdly-hrht", "ja7-6-5-7-0-4", "ld1-le-cmt-t-z", "hu2-wfkpj-jv", "iy0-hujr-wmrg-ca", "ia7-y-l-bnaz", "nr1-7-1-7-0-4", "gx0-sm-by-wd-ea" ]
        ArrayList<String> logs = new ArrayList<>();
        logs.add("qv4-tbojcv-yd");
        logs.add("uh9-lmtdpiunu");
        logs.add("ta9-5-3-5-5-1");
        logs.add("hn2-yawf-jw-zkw");
        logs.add("nc7-hdly-hrht");
        logs.add("ja7-6-5-7-0-4");
        logs.add("ld1-le-cmt-t-z");
        logs.add("hu2-wfkpj-jv");
        logs.add("iy0-hujr-wmrg-ca");
        logs.add("ia7-y-l-bnaz");
        logs.add("nr1-7-1-7-0-4");
        logs.add("gx0-sm-by-wd-ea");
        // Expected Output: [ "hu2-wfkpj-jv", "ia7-y-l-bnaz", "ld1-le-cmt-t-z", "hn2-yawf-jw-zkw", "iy0-hujr-wmrg-ca", "ja7-6-5-7-0-4", "nc7-hdly-hrht", "qv4-tbojcv-yd", "uh9-lmtdpiunu", "ta9-5-3-5-5-1", "nr1-7-1-7-0-4", "gx0-sm-by-wd-ea" ]
        ArrayList<String> reorderedLogs = obj.reorderLogs(logs);
        for (String log : reorderedLogs) {
            System.out.println(log);
        }
    }
}
