import sys
import math

def solution():
    inp = sys.stdin.readline
    (n, target), n_list = map(int, inp().split()), list(map(int, inp().split()))
    res = [0 for _ in range(target)]
    res[n_list[0] % target] += 1
    for i in range(1, n):
        n_list[i] = n_list[i] + n_list[i - 1]
        res[n_list[i] % target] += 1
    sum = res[0]
    for n in res:
        sum += math.comb(n, 2)
    print(sum)

if __name__ == "__main__":
    solution()
