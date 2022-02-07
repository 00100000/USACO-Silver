import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class bcount {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("bcount.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("bcount.out")));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int q = Integer.parseInt(st.nextToken());

		int[] one = new int[n + 1];
		int[] two = new int[n + 1];
		int[] three = new int[n + 1];
		for (int i = 1; i < n + 1; i++) {
			int cow = Integer.parseInt(br.readLine());
			one[i] = one[i - 1];
			two[i] = two[i - 1];
			three[i] = three[i - 1];
			if (cow == 1) {
				one[i]++;
			} else if (cow == 2) {
				two[i]++;
			} else {
				three[i]++;
			}
		}
		for (int i = 0; i < q; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
			pw.println((one[b] - one[a - 1]) + " " + (two[b] - two[a - 1]) + " " + (three[b] - three[a - 1]));
		}

		br.close();
		pw.close();
	}
}