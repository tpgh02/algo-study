import sys
input = sys.stdin.readline

n = int(input())
prices = list(map(int, input().split()))
prices[1] = max(prices[1], prices[0] * 2)
for i in range(2, n) :
    for j in range(i//2):
        prices[i] = max(prices[i], prices[j] + prices[i-j-1])
    if i%2 != 0 :
        prices[i] = max(prices[i], prices[i//2] * 2)

print(prices[-1])

# 10
# 1 1 2 3 5 8 13 21 34 55

# 1 2 3 4 5 8 13 21 34 55

# 10
# 5 10 11 12 13 30 35 40 45 47

# 5 10 15 20 25 30 35 40 45 50

# 6
# 1 5 7 8 9 10
