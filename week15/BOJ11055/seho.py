import sys
input = sys.stdin.readline

n = int(input())
nums = list(map(int, input().split()))
dp = nums.copy()
for i in range(1, n):
    for j in range(i):
        if nums[i] > nums[j] :
            dp[i] = max(nums[i] + dp[j], dp[i])
print(max(dp))