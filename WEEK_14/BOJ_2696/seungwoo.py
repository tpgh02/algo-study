import sys
import heapq

t = int(sys.stdin.readline())
for _ in range(t):
    n = int(sys.stdin.readline())
    count = 0
    li = []
    while count <= (n - 1) // 10:
        li += list(map(int, sys.stdin.readline().split()))
        count += 1
    max_hp = [-li[0]]
    min_hp = []
    check = -max_hp[0]
    res = [check]

    for i in range(1, len(li)):
        cur = li[i]
        if cur > check:
            heapq.heappush(min_hp, cur)
        else:
            heapq.heappush(max_hp, -cur)

        if i % 2 == 1:
            while len(max_hp) != len(min_hp):
                if len(max_hp) > len(min_hp):
                    heapq.heappush(min_hp, -heapq.heappop(max_hp))
                else:
                    heapq.heappush(max_hp, -heapq.heappop(min_hp))
            check = -max_hp[0]
        else:
            while len(max_hp) - 1 != len(min_hp):
                if len(max_hp) - 1 > len(min_hp):
                    heapq.heappush(min_hp, -heapq.heappop(max_hp))
                else:
                    heapq.heappush(max_hp, -heapq.heappop(min_hp))
            check = -max_hp[0]
            res.append(check)
    print(len(res))
    count = 0
    while count <= (len(res) - 1) // 10:
        print(*res[count * 10:min((count + 1) * 10, n)])
        count += 1
