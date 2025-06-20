import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class findDuplicateInArray {
    // DO NOT MODIFY THE LIST. IT IS READ ONLY
    public int repeatedNumber(final List<Integer> A) {
        Set<Integer> intSet = new HashSet<>();
        for (Integer integer : A) {
            if (intSet.contains(integer)) {
                return integer;
            } else {
                intSet.add(integer);
            }
        }
        return -1;
    }
    public static void main(String[] args) {
        // Example usage
        findDuplicateInArray finder = new findDuplicateInArray();
        List<Integer> inputList = List.of(1, 2, 3, 4, 5, 3);
        int result = finder.repeatedNumber(inputList);
        System.out.println("First duplicate number: " + result); // Output: First duplicate number: 3
    }
}

