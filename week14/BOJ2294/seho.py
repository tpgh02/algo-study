import sys
input = sys.stdin.readline

n, m = map(int, input().split())
coin = set([])
dp = [sys.maxsize for _ in range(m+1)]
dp[0] = 0
for _ in range(n):
    coin.add(int(input()))

coin = sorted(list(coin))

for c in coin:
    for i in range(c, m+1):
        dp[i] = min(dp[i], dp[i-c]+1)

if dp[-1] == sys.maxsize :
    print(-1)
else:
    print(dp[-1])

# 1 7 8 12

# 1 2 3 4 5 6 7 8 9 10 11 12
# 1 2 3 4 5 6 1 1 2