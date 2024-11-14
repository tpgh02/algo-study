package week10.BOJ1699;

import java.io.*;

public class seho {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int[] nums = new int[n+1];

        for (int i = 2; i <= n; i++) {
            nums[i] = 100000;
        }
        nums[0] = 0;
        nums[1] = 1;

        for (int i = 2; i <= n; i++) {
            for(int j = 1; j < i; j++) {
                if (j*j > i) {
                    break;
                }
                nums[i] = Math.min(nums[i], nums[i-j*j] + 1);
            }
        }
        System.out.println(nums[n]);

    }
}


// 1 2 3 / 1 2 3 4 2 / 1 2 3 4 2 2 3 / 1 2 2
// 1 2 3 / 4 5 6 7 8 / 9 10 11 12 13 14 15 / 16 17 18