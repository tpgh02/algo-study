import sys
from collections import deque
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    s = list(input().rstrip())
    n = int(input())
    if n == 0 :
        nums = input()
        nums = []
    else :
        nums = deque(list(map(int, input()[1:-2].split(","))))

    func = [0, "nums.pop()", "nums.popleft()"]

    fnum = -1

    for f in s :
        if f == "R":
            fnum *= -1
        else :
            if len(nums) == 0 :
                print("error")
                break
            exec(func[fnum])
    else :
        if fnum == 1 :
            nums.reverse()
        print("[{}]".format(",".join(str(x) for x in nums)))