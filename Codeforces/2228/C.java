import java.io.*;
import java.util.*;

public class C {

    static FastScanner sc = new FastScanner(System.in);
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {

        int t = sc.nextInt();
        while (t-- > 0)
            solve();
        System.out.println(sb);
    }

    static void solve() throws IOException {
        long a = sc.nextLong();
        int n = sc.nextInt();
        char[] s = Long.toString(a).toCharArray();
        int[] d = new int[n];
        boolean[] have = new boolean[10];
        for (int i = 0; i < n; i++) {
            d[i] = sc.nextInt();
            have[d[i]] = true;
        }
        // Arrays.sort(d);
        long[][] dp = new long[s.length + 1][3];
        for (int i = 0; i <= s.length; i++)
            for (int j = 0; j < 3; j++)
                dp[i][j] = -1;
        // 0 表示相等，1 表示小于的最大值，2 表示大于的最小值
        dp[0][0] = 0;
        // dp[0][2] = ;
        for (int i = 1; i <= 9; i++)
            if (have[i]) {
                dp[0][2] = i;
                break;
            }
        for (int i = 1; i <= s.length; i++) {
            int x = s[i - 1] - '0';
            if (dp[i - 1][0] != -1) {
                if (have[x])
                    dp[i][0] = dp[i - 1][0] * 10 + x;
                for (int j = x - 1; j >= 0; j--) {
                    if (have[j]) {
                        if (dp[i][1] == -1)
                            dp[i][1] = dp[i - 1][0] * 10 + j;
                        else
                            dp[i][1] = Math.max(dp[i][1], dp[i - 1][0] * 10 + j);
                        // break;
                    }
                }
                for (int j = x + 1; j <= 9; j++) {
                    // if (have[j]) {
                    // dp[i][2] = dp[i - 1][0] * 10 + j;
                    // break;
                    // }
                    if (have[j]) {
                        if (dp[i][2] == -1)
                            dp[i][2] = dp[i - 1][0] * 10 + j;
                        else
                            dp[i][2] = Math.min(dp[i][2], dp[i - 1][0] * 10 + j);
                        // break;
                    }
                }
            }

            if (dp[i - 1][1] != -1) {
                for (int j = 9; j >= 0; j--)
                    if (have[j]) {
                        if (dp[i][1] == -1)
                            dp[i][1] = dp[i - 1][1] * 10 + j;
                        else
                            dp[i][1] = Math.max(dp[i][1], dp[i - 1][1] * 10 + j);
                        // break;
                    }
            }
            if (dp[i - 1][2] != -1) {
                for (int j = 0; j <= 9; j++)
                    if (have[j]) {
                        if (dp[i][2] == -1)
                            dp[i][2] = dp[i - 1][2] * 10 + j;
                        else
                            dp[i][2] = Math.min(dp[i][2], dp[i - 1][2] * 10 + j);
                        // break;
                    }
            }
            dp[i][1] = Math.max(dp[i][1], 0);
        }
        long ans = Long.MAX_VALUE;
        if (dp[s.length][0] != -1)
            ans = 0;
        // System.out.println(ans);

        // System.out.println(Arrays.toString(dp[3]));
        if (dp[s.length][1] != -1)
            ans = Math.min(a - dp[s.length][1], ans);
        // System.out.println(ans);

        if (dp[s.length][2] != -1)
            ans = Math.min(dp[s.length][2] - a, ans);
        // System.out.println(ans);
        // long cur = 0;
        // while (cur < a) {
        // cur = cur * 10 + d[0];
        // ans = Math.min(ans, Math.abs(cur - a));
        // if (d[0] == 0)
        // break;
        // }
        // cur = 0;
        // while (cur < a) {
        // cur = cur * 10 + d[n - 1];
        // ans = Math.min(ans, Math.abs(cur - a));
        // if (d[n - 1] == 0)
        // break;
        // }
        sb.append(ans + "\n");
    }
    /*
     * 找一个大于 a 的最小的数字，
     * 和一个小于 a 的最大数字？
     * 
     * 假设长度为 l
     * l-1 个 d2
     * l+1 个 d1
     * 
     * 只用看 l 位的
     * dp[i][0] 比 a 小的最大数字，
     * dp[i][1] 比 a 大的最小的数字
     * dp[i][2] 前面的位和 a 相等的数字？
     */
}

class FastScanner {
    BufferedReader br;
    StringTokenizer st;

    public FastScanner(InputStream i) {
        br = new BufferedReader(new InputStreamReader(i));
        st = new StringTokenizer("");
    }

    public String next() throws IOException {
        while (!st.hasMoreTokens())
            st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

}