import sys
from collections import deque
input = sys.stdin.readline

s1 = deque(input().strip())
s2 = deque([])
n = int(input())

for _ in range(n):
    prefix = input().strip()
    if prefix[0] == 'D':
        if len(s2) != 0 :
            s1.append(s2.popleft())

    elif prefix[0] == 'L':
        if len(s1) != 0 :
            s2.appendleft(s1.pop())

    elif prefix[0] == 'B':
        if len(s1) != 0 :
            s1.pop()

    else :
        s1.append(prefix[-1])

print(''.join(s1) + ''.join(s2))
