import sys
from collections import Counter
input = sys.stdin.readline

n, m = map(int, input().split())
nums = list(map(int, input().split()))

for i in range(1, n):
    nums[i] = (nums[i] + nums[i-1]) % m # 누적합을 구하고 나눈 나머지
nums[0] %= m # nums[0]은 빠졌으니 따로 계산

c = Counter(nums)
ans = 0
for k, v in c.items():
    if k == 0:
        ans += v*(v+1)//2
    else:
        ans += v*(v-1)//2
print(ans)

# 1 2 3 1 2 2 2 1
# 1 3 6 7 9 11 13 14
# 1 0 0 1 0 2 1 2

# 7 +2

# 1 2 3 1 2 1
# 1 3 6 7 9 10
# 1 0 0 1 0 1
# 0 : 3+2+1
# 1 : 2+1