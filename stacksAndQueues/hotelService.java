package stacksAndQueues;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class hotelService {
    private int distanceBetweenPoints(int startX, int startY, int destX, int destY){
        return Math.abs(destX-startX) + Math.abs(destY-startY);
    }
    private int bfs(ArrayList<ArrayList<Integer>> A, int startX, int startY) {
        int m = A.size();
        int n = A.get(0).size();
        if (m == 1 && n == 1 && startX == 0 && startY == 0) {
            return 0;
        }
        int[][] visited = new int[m][n];
        Queue<ArrayList<Integer>> queue = new LinkedList<>();
        queue.add(new ArrayList<Integer>(java.util.Arrays.asList(startX, startY)));
        int[][] distance = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                distance[i][j] = -1;
            }
        }
        int x, y;
        while (!queue.isEmpty()) {
            x = queue.peek().get(0);
            y = queue.poll().get(1);
            if (visited[x][y] == 1) {
                continue;
            }
            visited[x][y] = 1;
            distance[x][y] = distanceBetweenPoints(startX, startY, x, y);
            if (A.get(x).get(y) == 1) {
                return distance[x][y];                
            }
            if (x - 1 >= 0 && visited[x - 1][y] == 0) {
                queue.add(new ArrayList<Integer>(java.util.Arrays.asList(x - 1, y)));
            }
            if (x + 1 < m && visited[x + 1][y] == 0) {
                queue.add(new ArrayList<Integer>(java.util.Arrays.asList(x + 1, y)));
            }
            if (y - 1 >= 0 && visited[x][y - 1] == 0) {
                queue.add(new ArrayList<Integer>(java.util.Arrays.asList(x, y - 1)));
            }
            if (y + 1 < n && visited[x][y + 1] == 0) {
                queue.add(new ArrayList<Integer>(java.util.Arrays.asList(x, y + 1)));
            }
        }
        return -1;
    }

    public ArrayList<Integer> nearestHotel(ArrayList<ArrayList<Integer>> A, ArrayList<ArrayList<Integer>> B) {
        int n = A.size(), m = A.get(0).size();
        ArrayList<Integer> result = new ArrayList<>();
        int[][] distanceFromAllPointsToNearestHotel = new int[n][m];
        for (int i = 0; i < n; i++) {
            java.util.Arrays.fill(distanceFromAllPointsToNearestHotel[i], -1);
        }
        Queue<int[]> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (A.get(i).get(j) == 1) {
                    queue.add(new int[]{i, j});
                    distanceFromAllPointsToNearestHotel[i][j] = 0;
                }
            }
        }
        while(!queue.isEmpty()) {
            int[] point = queue.poll();
            int x = point[0];
            int y = point[1];
            int currentDistance = distanceFromAllPointsToNearestHotel[x][y];
            int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (int[] dir : directions) {
                int newX = x + dir[0];
                int newY = y + dir[1];
                if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                    // visit unvisited non-hotel cells
                    if (A.get(newX).get(newY) != 1 && distanceFromAllPointsToNearestHotel[newX][newY] == -1) {
                        distanceFromAllPointsToNearestHotel[newX][newY] = currentDistance + 1;
                        queue.add(new int[]{newX, newY});
                    }
                }
            }
        }
        for (ArrayList<Integer> query : B) {
            int queryX = query.get(0)-1;
            int queryY = query.get(1)-1;
            result.add(distanceFromAllPointsToNearestHotel[queryX][queryY]);
        }
        return result;
    }
    public static void main(String[] args) {
//        A : 
// [
//   [0, 0, 1]
//   [1, 1, 0]
// ]
// B : 
// [
//   [1, 3]
//   [1, 1]
//   [1, 3]
//   [2, 2]
//   [1, 3]
// ]
        ArrayList<ArrayList<Integer>> A = new ArrayList<>();
        ArrayList<Integer> row1 = new ArrayList<>();
        row1.add(0);
        row1.add(0);
        row1.add(1);
        A.add(row1);
        ArrayList<Integer> row2 = new ArrayList<>();
        row2.add(1);
        row2.add(1);
        row2.add(0);
        A.add(row2);
        ArrayList<ArrayList<Integer>> B = new ArrayList<>();
        B.add(new ArrayList<Integer>(java.util.Arrays.asList(1, 3)));
        B.add(new ArrayList<Integer>(java.util.Arrays.asList(1, 1)));
        B.add(new ArrayList<Integer>(java.util.Arrays.asList(1, 3)));
        B.add(new ArrayList<Integer>(java.util.Arrays.asList(2, 2)));
        B.add(new ArrayList<Integer>(java.util.Arrays.asList(1, 3)));
        hotelService obj = new hotelService();
        ArrayList<Integer> result = obj.nearestHotel(A, B);
        System.out.println(result); // Expected Output: [0, 2, 0, 1, 0]
    }
}
