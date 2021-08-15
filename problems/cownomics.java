import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

class cownomics {
	public static void main(String[]args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("cownomics.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("cownomics.out")));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		String[] spotty = new String[n];
		String[] plain = new String[n];
		for (int i = 0; i < n; i++) spotty[i] = br.readLine();
		for (int i = 0; i < n; i++) plain[i] = br.readLine();
		// all possible gene combinations
		int valid = 0;
		for (int i = 0; i < m; i++) {
			for (int j = i + 1; j < m; j++) {
				for (int k = j + 1; k < m; k++) {
					// check if any gene combination from the 3 positions in the spotty or plain
					// cows are the same
					boolean isValid = true;
					for (int l = 0; l < n; l++) {
						for (int o = 0; o < n; o++) {
							if (spotty[l].charAt(i) == plain[o].charAt(i) &&
								spotty[l].charAt(j) == plain[o].charAt(j) &&
								spotty[l].charAt(k) == plain[o].charAt(k)) {
								isValid = false;
								break;
							}
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
	static int geneIndex(char gene) {
		switch (gene) {
			case 'A':
				return 0;
			case 'C':
				return 1;
			case 'G':
				return 2;
			case 'T':
				return 3;
		}
		return -1;
	}
}