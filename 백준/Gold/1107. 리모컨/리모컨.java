
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    public static Integer N, M, ans = 1000000000;
    public static ArrayList<Integer> errorNumbers;

    public static Integer calcLength(Integer nbr) {
        int cnt = 0;
        while (0 < nbr) {
            cnt++;
            nbr /= 10;
        }
        return cnt;
    }

    public static Integer min(Integer a, Integer b) {
        if (a < b) return a;
        return b;
    }

    public static Integer abs(Integer n) {
        if (n < 0)
            return -n;
        return n;
    }

    public static void dfs(Integer cur) {
        for (int i = 0; i <= 9; i++) {
            if (errorNumbers.contains(i))
                continue;
            if (i == 0 && cur.equals(0)) continue;
            Integer next = (cur * 10) + i;
            if (calcLength(next) <= 7) {
                ans = min(ans, abs(N - next) + calcLength(next));
                dfs(next);
            }
        }
    }

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        errorNumbers = new ArrayList<>();
        if (M.equals(0)) return ;
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            errorNumbers.add(Integer.parseInt(st.nextToken()));
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        ans = abs(N - 100);
        if (!errorNumbers.contains(0))
            ans = min(ans,  abs(N) + 1);
        dfs(0);
        System.out.println(ans);
    }
}
