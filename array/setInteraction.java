import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class setInteraction {
    public int setIntersection(ArrayList<ArrayList<Integer>> A) {
        A.sort(new Comparator<ArrayList<Integer>>() {
            @Override
            public int compare(ArrayList<Integer> o1, ArrayList<Integer> o2) {
                if (o1.get(1).equals(o2.get(1))) {
                    return o1.get(0).compareTo(o2.get(0));
                }
                return o1.get(1).compareTo(o2.get(1));
            }
        });
        ArrayList<Integer> intersection = new ArrayList<>();
        for (int i = 0; i < A.size(); i++) {
            int start = A.get(i).get(0);
            int end = A.get(i).get(1);
            int count = 0;
            for (Integer integer : intersection) {
                if (integer >= start && integer <= end) {
                    count++;
                }
                if (count >= 2) {
                    break;
                }
            }
            if (count == 0) {
                if (start == end) {
                    // Single point interval - add the point and one adjacent
                    intersection.add(start);
                    intersection.add(end);
                } else {
                    // Normal interval - add rightmost 2 points
                    intersection.add(end - 1);
                    intersection.add(end);
                }
            } else if (count == 1) {
                if (intersection.get(intersection.size() - 1) == end) {
                    intersection.add(end - 1);
                    continue;
                } else {
                    intersection.add(end);
                }
            }
        }
        return intersection.size();
    }

    public static void main(String[] args) {
        setInteraction si = new setInteraction();
        ArrayList<ArrayList<Integer>> A = new ArrayList<>();
        // A :
        // [
        // [131023, 281973]
        // [95954, 684758]
        // [566712, 883455]
        // [11010, 399592]
        // [675216, 919547]
        // [154170, 175566]
        // [29503, 489184]
        // [210136, 969361]
        // [123819, 896084]
        // [496723, 686536]
        // [16150, 252603]
        // [300483, 301030]
        // [17244, 376809]
        // [272656, 937168]
        // [276448, 529946]
        // [754345, 791540]
        // [30252, 499588]
        // [454973, 989600]
        // [422903, 453115]
        // [84010, 668505]
        // [3880, 407895]
        // [292019, 463799]
        // [564105, 988276]
        // [460243, 532373]
        // [111668, 177193]
        // [7007, 278472]
        // [56524, 403841]
        // [512321, 825122]
        // [420200, 577462]
        // [157623, 314379]
        // [64798, 253597]
        // [277153, 793846]
        // [38101, 313138]
        // [81596, 311224]
        // [156830, 340084]
        // [390449, 586882]
        // [135977, 925083]
        // [585209, 867210]
        // [82665, 95262]
        // [535579, 931865]
        // [185880, 980122]
        // [573635, 612733]
        // [229190, 758706]
        // [153023, 267743]
        // [341525, 938432]
        // [160272, 844600]
        // [79322, 810522]
        // [76641, 220519]
        // [249950, 526083]
        // [484931, 519874]
        // [360246, 941500]
        // [113581, 972451]
        // [728006, 973805]
        // [468947, 837082]
        // [261458, 876291]
        // [28, 82]
        // [39, 52]
        // [62, 94]
        // [73, 92]
        // [6, 62]
        // [37, 89]
        // [16, 25]
        // [22, 36]
        // [30, 58]
        // [30, 81]
        // [28, 36]
        // [10, 59]
        // [75, 76]
        // [68, 76]
        // [58, 66]
        // [52, 99]
        // [49, 68]
        // [51, 78]
        // [26, 35]
        // [12, 25]
        // [87, 98]
        // [8, 99]
        // [22, 94]
        // [1, 95]
        // [62, 88]
        // [20, 80]
        // [2, 77]
        // [32, 36]
        // [36, 37]
        // [53, 83]
        // [12, 17]
        // [1, 16]
        // [42, 66]
        // [33, 76]
        // [19, 89]
        // [61, 87]
        // [54, 62]
        // [83, 96]
        // [38, 81]
        // [69, 100]
        // [2, 55]
        // [41, 95]
        // [68, 91]
        // [22, 37]
        // [1, 45]
        // [43, 73]
        // [60, 81]
        // [40, 88]
        // [16, 22]
        // [26, 43]
        // [26, 28]
        // [40, 97]
        // [33, 65]
        // ]

        A.add(new ArrayList<>(List.of(131023, 281973)));
        A.add(new ArrayList<>(List.of(95954, 684758)));
        A.add(new ArrayList<>(List.of(566712, 883455)));
        A.add(new ArrayList<>(List.of(11010, 399592)));
        A.add(new ArrayList<>(List.of(675216, 919547)));
        A.add(new ArrayList<>(List.of(154170, 175566)));
        A.add(new ArrayList<>(List.of(29503, 489184)));
        A.add(new ArrayList<>(List.of(210136, 969361)));
        A.add(new ArrayList<>(List.of(123819, 896084)));
        A.add(new ArrayList<>(List.of(496723, 686536)));
        A.add(new ArrayList<>(List.of(16150, 252603)));
        A.add(new ArrayList<>(List.of(300483, 301030)));
        A.add(new ArrayList<>(List.of(17244, 376809)));
        A.add(new ArrayList<>(List.of(272656, 937168)));
        A.add(new ArrayList<>(List.of(276448, 529946)));
        A.add(new ArrayList<>(List.of(754345, 791540)));
        A.add(new ArrayList<>(List.of(30252, 499588)));
        A.add(new ArrayList<>(List.of(454973, 989600)));
        A.add(new ArrayList<>(List.of(422903, 453115)));
        A.add(new ArrayList<>(List.of(84010, 668505)));
        A.add(new ArrayList<>(List.of(3880, 407895)));
        A.add(new ArrayList<>(List.of(292019, 463799)));
        A.add(new ArrayList<>(List.of(564105, 988276)));
        A.add(new ArrayList<>(List.of(460243, 532373)));
        A.add(new ArrayList<>(List.of(111668, 177193)));
        A.add(new ArrayList<>(List.of(7007, 278472)));
        A.add(new ArrayList<>(List.of(56524, 403841)));
        A.add(new ArrayList<>(List.of(512321, 825122)));
        A.add(new ArrayList<>(List.of(420200, 577462)));
        A.add(new ArrayList<>(List.of(157623, 314379)));
        A.add(new ArrayList<>(List.of(64798, 253597)));
        A.add(new ArrayList<>(List.of(277153, 793846)));
        A.add(new ArrayList<>(List.of(38101, 313138)));
        A.add(new ArrayList<>(List.of(81596, 311224)));
        A.add(new ArrayList<>(List.of(156830, 340084)));
        A.add(new ArrayList<>(List.of(390449, 586882)));
        A.add(new ArrayList<>(List.of(135977, 925083)));
        A.add(new ArrayList<>(List.of(585209, 867210)));
        A.add(new ArrayList<>(List.of(82665, 95262)));
        A.add(new ArrayList<>(List.of(535579, 931865)));
        A.add(new ArrayList<>(List.of(185880, 980122)));
        A.add(new ArrayList<>(List.of(573635, 612733)));
        A.add(new ArrayList<>(List.of(229190, 758706)));
        A.add(new ArrayList<>(List.of(153023, 267743)));
        A.add(new ArrayList<>(List.of(341525, 938432)));
        A.add(new ArrayList<>(List.of(160272, 844600)));
        A.add(new ArrayList<>(List.of(79322, 810522)));
        A.add(new ArrayList<>(List.of(76641, 220519)));
        A.add(new ArrayList<>(List.of(249950, 526083)));
        A.add(new ArrayList<>(List.of(484931, 519874)));
        A.add(new ArrayList<>(List.of(360246, 941500)));
        A.add(new ArrayList<>(List.of(113581, 972451)));
        A.add(new ArrayList<>(List.of(728006, 973805)));
        A.add(new ArrayList<>(List.of(468947, 837082)));
        A.add(new ArrayList<>(List.of(261458, 876291)));
        A.add(new ArrayList<>(List.of(28, 82)));
        A.add(new ArrayList<>(List.of(39, 52)));
        A.add(new ArrayList<>(List.of(62, 94)));
        A.add(new ArrayList<>(List.of(73, 92)));
        A.add(new ArrayList<>(List.of(6, 62)));
        A.add(new ArrayList<>(List.of(37, 89)));
        A.add(new ArrayList<>(List.of(16, 25)));
        A.add(new ArrayList<>(List.of(22, 36)));
        A.add(new ArrayList<>(List.of(30, 58)));
        A.add(new ArrayList<>(List.of(30, 81)));
        A.add(new ArrayList<>(List.of(28, 36)));
        A.add(new ArrayList<>(List.of(10, 59)));
        A.add(new ArrayList<>(List.of(75, 76)));
        A.add(new ArrayList<>(List.of(68, 76)));
        A.add(new ArrayList<>(List.of(58, 66)));
        A.add(new ArrayList<>(List.of(52, 99)));
        A.add(new ArrayList<>(List.of(49, 68)));
        A.add(new ArrayList<>(List.of(51, 78)));
        A.add(new ArrayList<>(List.of(26, 35)));
        A.add(new ArrayList<>(List.of(12, 25)));
        A.add(new ArrayList<>(List.of(87, 98)));
        A.add(new ArrayList<>(List.of(8, 99)));
        A.add(new ArrayList<>(List.of(22, 94)));
        A.add(new ArrayList<>(List.of(1, 95)));
        A.add(new ArrayList<>(List.of(62, 88)));
        A.add(new ArrayList<>(List.of(20, 80)));
        A.add(new ArrayList<>(List.of(2, 77)));
        A.add(new ArrayList<>(List.of(32, 36)));
        A.add(new ArrayList<>(List.of(36, 37)));
        A.add(new ArrayList<>(List.of(53, 83)));
        A.add(new ArrayList<>(List.of(12, 17)));
        A.add(new ArrayList<>(List.of(1, 16)));
        A.add(new ArrayList<>(List.of(42, 66)));
        A.add(new ArrayList<>(List.of(33, 76)));
        A.add(new ArrayList<>(List.of(19, 89)));
        A.add(new ArrayList<>(List.of(61, 87)));
        A.add(new ArrayList<>(List.of(54, 62)));
        A.add(new ArrayList<>(List.of(83, 96)));
        A.add(new ArrayList<>(List.of(38, 81)));
        A.add(new ArrayList<>(List.of(69, 100)));
        A.add(new ArrayList<>(List.of(2, 55)));
        A.add(new ArrayList<>(List.of(41, 95)));
        A.add(new ArrayList<>(List.of(68, 91)));
        A.add(new ArrayList<>(List.of(22, 37)));
        A.add(new ArrayList<>(List.of(1, 45)));
        A.add(new ArrayList<>(List.of(43, 73)));
        A.add(new ArrayList<>(List.of(60, 81)));
        A.add(new ArrayList<>(List.of(40, 88)));
        A.add(new ArrayList<>(List.of(16, 22)));
        A.add(new ArrayList<>(List.of(26, 43)));
        A.add(new ArrayList<>(List.of(26, 28)));
        A.add(new ArrayList<>(List.of(40, 97)));
        A.add(new ArrayList<>(List.of(33, 65)));
        System.out.println("Size of intersection: " + si.setIntersection(A));

        // A = [[1, 3], [1, 4], [2, 5], [3, 5]]
        // A.clear();
        // A.add(new ArrayList<>(List.of(1, 3)));
        // A.add(new ArrayList<>(List.of(1, 4)));
        // A.add(new ArrayList<>(List.of(2, 5)));
        // A.add(new ArrayList<>(List.of(3, 5)));
        // System.out.println("Size of intersection: " + si.setIntersection(A));

        // // Input 2:

        // // A = [[1, 2], [2, 3], [2, 4], [4, 5]]
        // A.clear();
        // A.add(new ArrayList<>(List.of(1, 2)));
        // A.add(new ArrayList<>(List.of(2, 3)));
        // A.add(new ArrayList<>(List.of(2, 4)));
        // A.add(new ArrayList<>(List.of(4, 5)));
        // System.out.println("Size of intersection: " + si.setIntersection(A));
    }
}
