import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

class berries {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("berries.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("berries.out")));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());

		int[] tree = new int[n];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			tree[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(tree);
		// each of Elsie's baskets should have i berries, while Bessie's baskets should have mid
		// or less berries. Check every possible value of i.
		int max = 0;
		for (int i = 1; i <= 1000; i++) {
			int[] basket = new int[k];
			int[] tempTree = new int[n];
			// copy over tree values backwards because trees is sorted in increasing order
			for (int j = 0; j < n; j++) {
				tempTree[j] = tree[n - j - 1];
			}
			// fill up all baskets with at least t berries
			int j = 0;
			for (int l = 0; j < k; j++, l++) {
				if (tempTree[l] >= i) {
					basket[j] = i;
					tempTree[l] -= i;
					// if tree can fill another basket
					if (tempTree[l] >= i) {
						l--;
					}
				} else {
					break;
				}
			}
			// fill up rest of baskets with most under i berries
			Arrays.sort(tempTree);
			for (int l = n - 1; j < k && l > 0; j++, l--) {
				basket[j] = tempTree[l];
				tempTree[l] = 0;
			}
			// find the value of i for which bessie has the most berries
			int temp = 0;
			for (int l = k / 2; l < k; l++) {
				temp += basket[l];
			}
			max = Math.max(max, temp);
		}

		pw.print(max);
		br.close();
		pw.close();
	}
}