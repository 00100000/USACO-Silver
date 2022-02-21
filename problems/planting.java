import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class planting {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("planting.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("planting.out")));

		int n = Integer.parseInt(br.readLine());

		int[] list = new int[n];
		for (int i = 0; i < n - 1; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken()) - 1;
			int b = Integer.parseInt(st.nextToken()) - 1;
			list[a]++;
			list[b]++;
		}
		// find node with most neighbors
		int max = 0;
		for (int i = 0; i < n; i++) {
			max = Math.max(max, list[i]);
		}

		pw.print(max + 1);
		br.close();
		pw.close();
	}
}