import sys
import heapq

def solution():

    def get_parent(a):
        while p[a] != a:
            a = p[a]
        return a

    def union_parent(a, b):
        pa, pb = get_parent(a), get_parent(b)
        if pa > pb:
            p[pa] = pb
        else:
            p[pb] = pa

    inp = sys.stdin.readline
    n, m = map(int, inp().split())
    p, q = [i for i in range(n + 1)], []
    for _ in range(m):
        a, b, c = map(int, inp().split())
        heapq.heappush(q, (c, a, b))
    
    res = 0
    for _ in range(n - 2):
        c, a, b = heapq.heappop(q)
        while get_parent(a) == get_parent(b):
            c, a, b = heapq.heappop(q)
        res += c
        union_parent(a, b)
    
    print(res)

if __name__ == "__main__":
    solution()
