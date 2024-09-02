package week10.BOJ16562;

import java.util.*;
import java.io.*;

public class seho {
    static int[] parent;
    static int[] money;

    static int find(int x){
        if (parent[x] == x) return parent[x];

        parent[x] = find(parent[x]);
        return parent[x];
    }

    static void union(int a, int b){
        a = find(a);
        b = find(b);

        if (money[a] > money[b]) parent[a] = b;
        else parent[b] = a;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        money = new int[n];
        parent = new int[n];

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++) {
            money[i] = Integer.parseInt(st.nextToken());
            parent[i] = i;
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken())-1;
            int b = Integer.parseInt(st.nextToken())-1;

            if (find(a) != find(b)) {
                union(a, b);
            }
        }

        int[] set = Arrays.stream(parent).distinct().toArray();
        boolean[] visited = new boolean[n];
        int ans = 0;
        for(int friend : set){
            friend = find(friend);
            if (visited[friend]) continue;
            ans += money[friend];
            visited[friend] = true;

        }

        if (ans > k)  System.out.println("Oh no");
        else  System.out.println(ans);
    }
}