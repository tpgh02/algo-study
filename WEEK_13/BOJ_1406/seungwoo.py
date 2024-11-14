import sys

from collections import deque
def main():
    inp = sys.stdin.readline
    left, right = deque(list(inp().rstrip())), deque()
    for _ in range(int(inp())):
        cmd = inp().rstrip()
        try:
            if cmd == 'L':
                # pop/append is faster then pop/append left
                right.append(left.pop())
            elif cmd == 'D':
                left.append(right.pop())
            elif cmd == 'B':
                left.pop()
            else:
                left.append(cmd[-1])
        # Stopping process within OS level is much fater than diverging case
        except: 
            continue

    print(''.join(left), ''.join(reversed(right)), sep='')

if __name__ == "__main__":
    main()
