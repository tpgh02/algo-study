package week10.BOJ3055;

import java.util.*;
import java.io.*;

public class seho {
    static char[][] map;
    static int n;
    static int m;
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};

    static int move(){
        Queue<int[]> wq = new LinkedList<>();
        Queue<int[]> hq = new LinkedList<>();
        int ans = 0;
        boolean[][] visited = new boolean[n][m];

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (map[i][j] == '*'){
                    wq.add(new int[]{i, j});
                }
                if (map[i][j] == 'S'){
                    hq.add(new int[]{i, j});
                }
            }
        }

        while (!wq.isEmpty() || !hq.isEmpty()){
            int wl = wq.size();
            for (int i = 0; i < wl; i++){
                int[] tmp = wq.poll();
                int y = tmp[0]; int x = tmp[1];

                for (int k = 0; k < 4; k++){
                    int nx = x + dx[k]; int ny = y + dy[k];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || map[ny][nx] != '.') continue;

                    map[ny][nx] = '*';
                    wq.add(new int[]{ny, nx});
                }
            }

            int hl = hq.size();
            for (int i = 0; i < hl; i++){
                int[] tmp = hq.poll();
                int y = tmp[0]; int x = tmp[1];
                if (map[y][x] == 'D') return ans;

                for (int k = 0; k < 4; k++){
                    int nx = x + dx[k]; int ny = y + dy[k];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || (map[ny][nx] != '.' && map[ny][nx] != 'D') || visited[ny][nx]) continue;

                    hq.add(new int[]{ny, nx});
                    visited[ny][nx] = true;
                }
            }
            if (hq.isEmpty()) return -1;
            ans++;
        }
        return ans;
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new char[n][m];

        for (int i = 0; i < n; i++) {
            map[i] = br.readLine().toCharArray();
        }

        int ans = move();
        if (ans < 0) System.out.println("KAKTUS");
        else System.out.println(ans);
    }
}
