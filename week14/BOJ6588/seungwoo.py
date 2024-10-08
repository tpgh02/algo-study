import sys

def solution():
    inp = sys.stdin.readline
    dec_list = [True] * 1000001
    for n in range(3, 1000000, 2):
        if dec_list[n]:
            for ptr in range(n + n, 1000001, n):
                dec_list[ptr] = False
    
    while (target:= int(inp())):
        for p in range(3, 500001, 2):
            if dec_list[p] and dec_list[target - p]:
                print("%d = %d + %d"%(target, p, target - p))
                break
        else:
            print("Goldbach's conjecture is wrong.")

if __name__ == "__main__":
    solution()
