import sys
import time
input = sys.stdin.readline

prime = [i for i in range(1000001)]
for i in range(2, 1000001):
    if prime[i] == 0 :
        continue

    for j in range(i+i, 1000001, i):
        prime[j] = 0

prime = sorted(list(set(prime)))[2:]
setPrime = set(prime)

while True:
    n = int(input())
    if n == 0 :
        break

    flag = False
    for i in range(len(prime)):
        if n-prime[i] in setPrime :
            print("{} = {} + {}".format(n, prime[i], n-prime[i]))
            break
        if prime[i] > n//2 :
            flag = True
            break
    if flag:
        print("Goldbach's conjecture is wrong.")