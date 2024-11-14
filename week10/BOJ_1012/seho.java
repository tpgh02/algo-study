package week10.BOJ1012;

import java.util.*;
import java.io.*;

public class seho {
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};
    static int[][] farm;
    static int ans;
    static int n;
    static int m;
    static boolean[][] visited;

    static void bfs(int a, int b) {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[] {a, b});
        visited[a][b] = true;

        while (!q.isEmpty()) {
            int[] temp = q.poll();
            int x = temp[1], y = temp[0];

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || ny < 0 || nx >= m || ny >= n || visited[ny][nx] || farm[ny][nx] == 0) continue;
                visited[ny][nx] = true;
                q.add(new int[] {ny, nx});
            }
        }
        ans++;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());

        for (int t = 0; t < T; t++) {
            st = new StringTokenizer(br.readLine());
            m = Integer.parseInt(st.nextToken());
            n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());

            farm = new int[n][m];
            visited = new boolean[n][m];
            ans = 0;

            for (int i = 1; i <= k; i++) {
                st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());

                farm[y][x] = 1;
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (farm[i][j] == 1 && !visited[i][j]) {
                        bfs(i, j);
                    }
                }
            }
            System.out.println(ans);
        }
    }
}
