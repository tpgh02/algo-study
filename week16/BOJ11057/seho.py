n = int(input())

dp = [[1 for _ in range(10)]]
dp += [[1 for _ in range(10)] for _ in range(n)]

for i in range(1, n+1):
    for j in range(1, 10):
        dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 10007

print(dp[-1][-1])