import sys
from math import sqrt

input = sys.stdin.readline

n, m = map(int, input().split())

nums = [True for _ in range(m-n+1)]

sq = []
tmp = int(sqrt(m))
for i in range(2, tmp+1):
    sq.append(i*i)

for divide in sq:
    i = divide - n
    while i < len(nums) :
        if i >= 0 :
            nums[i] = False
            i += divide
        else :
            i += ((-1 * i) // divide) * divide
            if i < 0 :
                i += divide

print(sum(nums))