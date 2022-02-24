import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class div7 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("div7.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("div7.out")));

		int n = Integer.parseInt(br.readLine());

		int[] pSum = new int[n];
		pSum[0] = Integer.parseInt(br.readLine());
		for (int i = 1; i < n; i++) {
			// we only need to track the remainder if each prefix sum is divided by 7
			pSum[i] = (pSum[i - 1] + Integer.parseInt(br.readLine())) % 7;
		}
		// find the max distance between two prefix sums from the left and right whose remainders
		// are equal
		int max = 0;
		for (int i = 0; i < 7; i++) {
			int j = 0;
			for (; j < n; j++) {
				if (pSum[j] == i) break;
			}
			int k = n - 1;
			for (; k >= 0; k--) {
				if (pSum[k] == i) break;
			}
			max = Math.max(max, k - j);
		}

		pw.print(max);
		br.close();
		pw.close();
	}
}