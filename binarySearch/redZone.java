package binarySearch;

import java.util.ArrayList;
// TODO: Will be done later on

public class redZone {
    public double distanceBetweenPoints(int x1, int y1, int x2, int y2) {
        return Math.sqrt(Math.pow(x1 - x2, 2) + Math.pow(y1 - y2, 2));
    }

    public int solve(ArrayList<ArrayList<Integer>> A, int B) {
        double maxDistanceBetweenAnyTwoPoints = 0;
        double minDistanceBetweenAnyTwoPoints = Double.MAX_VALUE;
        int distanceBetweenPoints;
        for (int i = 0; i < A.size() - 1; i++) {
            for (int j = i + 1; j < A.size(); j++) {
                distanceBetweenPoints = (int) distanceBetweenPoints(A.get(i).get(0), A.get(i).get(1), A.get(j).get(0), A.get(j).get(1));
                minDistanceBetweenAnyTwoPoints = Math.min(minDistanceBetweenAnyTwoPoints, distanceBetweenPoints);
                maxDistanceBetweenAnyTwoPoints = Math.max(maxDistanceBetweenAnyTwoPoints, distanceBetweenPoints);}
        }
        int maxDiameter = ((int) maxDistanceBetweenAnyTwoPoints+1);
        int low = (int) minDistanceBetweenAnyTwoPoints/2, high = maxDiameter, mid;
        int result = -1;
        while (low<=high) {
            mid = (high+low)/2;
            int maxCountOfPointsInsideCircle = -1;
            for (int i = 0; i < A.size(); i++) {
                int countOfPointsInsideCircle = 0;
                for (int j = 0; j < A.size(); j++) {
                    if (distanceBetweenPoints(A.get(i).get(0), A.get(i).get(1), A.get(j).get(0), A.get(j).get(1)) <= 2*mid && i!=j) {
                        countOfPointsInsideCircle++;
                    }
                }
                maxCountOfPointsInsideCircle = Math.max(countOfPointsInsideCircle, maxCountOfPointsInsideCircle);
            }
            if (maxCountOfPointsInsideCircle >= B){
                result = mid;
                high = mid-1;
            }
            else if (maxCountOfPointsInsideCircle < B-1){
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return result;
    }
    public static void main(String[] args) {
        // A : 
        // [
        //   [8, 5]
        //   [0, 4]
        //   [3, 6]
        // ]
        // B : 3
        ArrayList<ArrayList<Integer>> A = new ArrayList<>();
        ArrayList<Integer> point1 = new ArrayList<>();
        point1.add(8);
        point1.add(5);
        A.add(point1);
        ArrayList<Integer> point2 = new ArrayList<>();
        point2.add(0);
        point2.add(4);
        A.add(point2);
        ArrayList<Integer> point3 = new ArrayList<>();
        point3.add(3);
        point3.add(6);
        A.add(point3);
        int B = 3;
        redZone obj = new redZone();
        System.out.println(obj.solve(A, B));
    }
}