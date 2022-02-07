import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.StringTokenizer;

public class cownomics {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("cownomics.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("cownomics.out")));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		String[] spotty = new String[n];
		String[] plain = new String[n];
		for (int i = 0; i < n; i++) spotty[i] = br.readLine();
		for (int i = 0; i < n; i++) plain[i] = br.readLine();
		// check how many combinations of 3 spotty genes don't overlap
		// with the genes mapped to seen
		int valid = 0;
		for (int i = 0; i < m; i++) {
			for (int j = i + 1; j < m; j++) {
				for (int k = j + 1; k < m; k++) {
					HashMap<String, Boolean> seen = new HashMap<String, Boolean>(0);
					// map all the combinations of 3 plain genes to seen
					for (int l = 0; l < n; l++) {
						String check = "" + plain[l].charAt(i) + plain[l].charAt(j) + plain[l].charAt(k);
						seen.put(check, false);
					}
					boolean isValid = true;
					for (int l = 0; l < n; l++) {
						String check = "" + spotty[l].charAt(i) + spotty[l].charAt(j) + spotty[l].charAt(k);
						if (seen.containsKey(check)) {
							isValid = false;
							break;
						}
					}
					if (isValid) valid++;
				}
			}
		}

		pw.print(valid);
		br.close();
		pw.close();
	}
}