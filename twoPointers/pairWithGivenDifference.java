package twoPointers;

import java.util.ArrayList;
import java.util.Collections;

public class pairWithGivenDifference {
    public int solve(ArrayList<Integer> A, int B) {
        if (A == null || A.size() < 2) {
            return 0;
        }
        B = Math.abs(B);
        Collections.sort(A);
        int n = A.size();
        int left = 0, right = 1, diff;
        while (left < n && right < n) {
            diff = A.get(right) - A.get(left);
            if (diff == B) {
                return 1;
            } else if (diff < B) {
                right++;
            } else {
                left++;
                if (left == right) {
                    right++;
                }
            }
        }
        return 0;
    }

    public static void main(String[] args) {
        // 42 -533 -666 -500 169 724 478 358 -38 -536 705 -855 281 -173 961 -509 -5 942
        // -173 436 -609 -396 902 -847 -708 -618 421 -284 718 895 447 726 -229 538 869
        // 912 667 -701 35 894 -297 811 322 369
        int n = 42;
        ArrayList<Integer> A = new ArrayList<>();
        A.add(-533);
        A.add(-666);
        A.add(-500);
        A.add(169);
        A.add(724);
        A.add(478);
        A.add(358);
        A.add(-38);
        A.add(-536);
        A.add(705);
        A.add(-855);
        A.add(281);
        A.add(-173);
        A.add(961);
        A.add(-509);
        A.add(-5);
        A.add(942);
        A.add(-173);
        A.add(436);
        A.add(-609);
        A.add(-396);
        A.add(902);
        A.add(-847);
        A.add(-708);
        A.add(-618);
        A.add(421);
        A.add(-284);
        A.add(718);
        A.add(895);
        A.add(447);
        A.add(726);
        A.add(-229);
        A.add(538);
        A.add(869);
        A.add(912);
        A.add(667);
        A.add(-701);
        A.add(35);
        A.add(894);
        A.add(-297);
        A.add(811);
        A.add(322);
        A.add(369);
        int B = 704;
        pairWithGivenDifference obj = new pairWithGivenDifference();
        System.out.println(obj.solve(A, B));
    }
}
