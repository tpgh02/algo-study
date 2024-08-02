import sys

input = sys.stdin.readline

def dfs(dic, num, ite):
    global ans_len
    global ans
    ch = num[ite]

    if not (dic.get(-1) is None):
        ans = True
        return

    if dic.get(ch) is None:
        dic[ch] = {}
        if ite == ans_len-1 :
            dic[ch][-1] = True
        return

    ite += 1
    if ite >= len(num):
        return

    dfs(dic[ch], num, ite)

t = int(input())

for _ in range(t):
    n = int(input())

    nums = []
    li = {}
    ans = False
    for _ in range(n):
        nums.append(input().rstrip())
    nums.sort()

    for num in nums:
        ans_len = len(num)

        for i in range(1, len(num)+1):
            dfs(li, num[:i], 0)
            if ans :
                break
        if ans:
            print("NO")
            break
    else : print("YES")
