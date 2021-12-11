import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

class balancing {
	static class Cow {
		int x, y;
	}
	public static void main(String[]args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("balancing.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("balancing.out")));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		Cow[] cow = new Cow[n];

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			Cow c = new Cow();
			c.x = Integer.parseInt(st.nextToken());
			c.y = Integer.parseInt(st.nextToken());
			cow[i] = c;
		}
		// sort cows by y so finding their quadrant is faster
		Arrays.sort(cow, new Comparator<Cow>() {
			@Override
			public int compare(Cow a, Cow b) {
				return a.y - b.y;
			}
		});

		int min = Integer.MAX_VALUE;
		for (int i = 0; i < n; i++) {
			int x = cow[i].x + 1;
			// track cows to the left and right of x
			ArrayList<Cow> left = new ArrayList<Cow>(0);
			ArrayList<Cow> right = new ArrayList<Cow>(0);
			for (int j = 0; j < n; j++) {
				if (x > cow[j].x) {
					left.add(cow[j]);
				} else {
					right.add(cow[j]);
				}
			}
			// count the number of cows in each quadrant
			// for each new y, we only need to account for the cows between the last y checked and this y
			int leftIndex = 0, rightIndex = 0;
			int topL = left.size(), topR = right.size(), botL = 0, botR = 0;
			for (int j = 0; j < n; j++) {
				int y = cow[j].y + 1;
				if (leftIndex >= left.size() || rightIndex >= right.size()) break;
				while (left.get(leftIndex).y < y) {
					botL++;
					topL--;
					leftIndex++;
					if (leftIndex >= left.size()) break;
				}
				while (right.get(rightIndex).y < y && rightIndex < right.size()) {
					botR++;
					topR--;
					rightIndex++;
					if (rightIndex >= right.size()) break;
				}
				min = Math.min(min, largest(topR, topL, botR, botL));
			}
		}

		pw.println(min);
		br.close();
		pw.close();
	}
	static int largest(int a, int b, int c, int d) {
		return Math.max(Math.max(Math.max(a, b), c), d);
	}
}
