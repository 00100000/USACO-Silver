import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.StringTokenizer;

class citystate {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("citystate.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("citystate.out")));

		int n = Integer.parseInt(br.readLine());

		HashMap<String, Integer> map = new HashMap<String, Integer>(0);
		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			// s = first 2 letters of city name + state name
			String s = st.nextToken().substring(0, 2) + st.nextToken();
			// if state and city have the same name, there's no need to consider it
			if (s.substring(0, 2).equals(s.substring(2, 4))) continue;
			if (map.containsKey(s)) {
				map.put(s, map.get(s) + 1);
			} else {
				map.put(s, 1);
			}
		}
		// check map
		int cnt = 0;
		for (String k : map.keySet()) {
			// if map contains key equal to k with the city and state swapped
			String swapped = k.substring(2, 4) + k.substring(0, 2);
			if (map.containsKey(swapped)) {
				// multiple because each city with key k can be matched with all the cities with
				// key swapped
				cnt += map.get(k) * map.get(swapped);
			}
		}
		// we counted each pair twice, as to not deal with ConcurrentModificationException
		pw.print(cnt / 2);
		br.close();
		pw.close();
	}
}
