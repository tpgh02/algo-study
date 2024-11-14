import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())

nums = [deque([0 for _ in range(n + 1)])]
for _ in range(n):
    tmp = deque(map(int, input().split()))
    tmp.appendleft(0)
    for i in range(1, n+1):
        tmp[i] += tmp[i-1]

    nums.append(tmp)

for i in range(1, n+1):
    for j in range(1, n+1):
        nums[i][j] += nums[i-1][j]

for _ in range(m):
    x1, y1, x2, y2 = map(int, input().split())

    ans = nums[x2][y2] - nums[x1-1][y2] - nums[x2][y1-1] + nums[x1-1][y1-1]

    print(ans)
# 1 3 6 10