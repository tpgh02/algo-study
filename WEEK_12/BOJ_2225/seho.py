import sys
input = sys.stdin.readline

n, k = map(int, input().split())

# 0, 1, 2, 3, 4, 5, 6

# k = 1 / 1 1 1 1 1 1 1 1 ...
# k = 2 / 2 3 4 5 6 7 8 9 ...
# k = 3 / 3 6 10 15 ...

dp = [[0 for _ in range(n)] for _ in range(k)]

for i in range(n):
    dp[0][i] = 1
for i in range(k):
    dp[i][0] = i+1

for j in range(1, n):
    for i in range(1, k):
        dp[i][j] = (dp[i-1][j] % 1000000000 + dp[i][j-1] % 1000000000) % 1000000000

print(dp[-1][-1])