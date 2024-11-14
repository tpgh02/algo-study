#에디터 1406

#그냥 리스트로 하면 시간초과 => 큐 이용해서 커서를 기준으로 왼쪽, 오른쪽 배열 두개로 나눠서 구현
import sys
from collections import deque

#커서기준 왼쪽 오른쪽 글자 배열
left = list(input())
right = []

n = int(input())
for i in range(n):
    order = input()
    if order[0] == 'L':
        if left:
            right.append(left.pop())
    elif order[0] == 'D':
        if right:
            left.append(right.pop())
    elif order[0] == 'B':
        if left:
            left.pop()
    else:
        left.append(order[2])
        
left.extend(reversed(right))
print(''.join(left))