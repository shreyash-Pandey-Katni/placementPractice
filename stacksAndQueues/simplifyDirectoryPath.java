package stacksAndQueues;

public class simplifyDirectoryPath {
    public String simplifyPath(String A) {
        String[] paths = A.split("/");
        java.util.Stack<String> stack = new java.util.Stack<>();
        for (String path : paths) {
            if (path.equals("") || path.equals(".")) {
                continue;
            } else if (path.equals("..")) {
                if (!stack.isEmpty()) {
                    stack.pop();
                }
            } else {
                stack.push(path);
            }
        }
        StringBuilder result = new StringBuilder();
        if (stack.isEmpty()) {
            return "/";
        }
        for (String dir : stack) {
            result.append("/").append(dir);
        }
        return result.toString();
    }
}
