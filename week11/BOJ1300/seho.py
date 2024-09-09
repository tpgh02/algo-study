import sys
input = sys.stdin.readline

n = int(input()) # 100000
k = int(input())

s, e = 1, k

while s <= e :
    m = (s + e) // 2

    tmp = 0
    for i in range(1, n+1):
        tmp += min(m//i, n)

    if tmp >= k:
        ans = m
        e = m-1
    else :
        s = m+1

print(ans)
# 1

# 1 2
# 2 4

# 1 2 3
# 2 4 6
# 3 6 9
# => 1 2 2 3 3 4 6 6 9

# 1 2 3 4
# 2 4 6 8
# 3 6 9 12
# 4 8 12 16
# => 1 2 2 3 3 4 4 4 6 6 8 8 9 12 12 16

# 1 2 3 4 5
# 2 4 6 8 10
# 3 6 9 12 15
# 4 8 12 16 20
# 5 10 15 20 25