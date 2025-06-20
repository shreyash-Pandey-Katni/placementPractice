import java.util.ArrayList;
import java.util.Comparator;

public class hotelBookingsPossible {
    public boolean hotel(ArrayList<Integer> arrive, ArrayList<Integer> depart, int K) {
        ArrayList<ArrayList<Integer>> events = new ArrayList<>();
        int numberOfBookings = arrive.size();
        for (int i = 0; i < numberOfBookings; i++) {
            ArrayList<Integer> arrivalEvent = new ArrayList<>();
            arrivalEvent.add(arrive.get(i));
            arrivalEvent.add(1); // 1 for arrival
            events.add(arrivalEvent);

            ArrayList<Integer> departureEvent = new ArrayList<>();
            departureEvent.add(depart.get(i));
            departureEvent.add(-1); // -1 for departure
            events.add(departureEvent);
        }
        events.sort(new Comparator<ArrayList<Integer>>() {
            @Override
            public int compare(ArrayList<Integer> o1, ArrayList<Integer> o2) {
                if (o1.get(0).equals(o2.get(0))) {
                    return o2.get(1) - o1.get(1); // Sort by type if times are equal
                }
                return o1.get(0) - o2.get(0); // Sort by time
            }
        });
        int count = 0;
        int maxCount = Integer.MIN_VALUE;
        for (ArrayList<Integer> event : events) {
            if (event.get(1) == 1) { // Arrival
                count++;
            } else { // Departure
                count--;
            }
            maxCount = Math.max(maxCount, count);
        }
        return maxCount <= K;
    }

    public static void main(String[] args) {
        hotelBookingsPossible hbp = new hotelBookingsPossible();
        ArrayList<Integer> arrive = new ArrayList<>();
        ArrayList<Integer> depart = new ArrayList<>();

        // A : [ 10, 19 ]
        // B : [ 19, 38 ]
        // C : 1
        arrive.add(10);
        arrive.add(19);
        depart.add(19);
        depart.add(38);
        int K = 1; // Maximum number of rooms available

        boolean result = hbp.hotel(arrive, depart, K);
        System.out.println("Can all bookings be accommodated? " + result);
    }
}
