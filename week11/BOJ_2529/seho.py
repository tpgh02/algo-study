import sys
from collections import deque

input = sys.stdin.readline

n = int(input())

prefix = input().split()
maxNums = deque([str(x) for x in range(10)])
minNums = deque([str(x) for x in range(10)])

minN = ""
tmpMin = ""
maxN = ""
tmpMax = ""

for ch in prefix :
    if ch == ">" :
        maxN = maxN + maxNums.pop() + tmpMax
        tmpMax = ""
        tmpMin = minNums.popleft() + tmpMin
    else :
        tmpMax = maxNums.pop() + tmpMax
        minN = minN + minNums.popleft() + tmpMin
        tmpMin = ""

maxN = maxN + maxNums.pop() + tmpMax
minN = minN + minNums.popleft() + tmpMin
print(maxN)
print(minN)