import sys

def solution():
    inp = sys.stdin.readline
    a = int(inp())
    n_list = list(map(int, inp().split()))
    dp = [0 for _ in range(a)]
    dp[0] = n_list[0]
    for i in range(1, a):
        maxV = 0
        for j in range(i):
            if n_list[j] < n_list[i]:
                maxV = max(maxV, dp[j])
        dp[i] = maxV + n_list[i]
    print(max(dp))

if __name__ == "__main__":
    solution()
