import sys

def solution():
    def choose_num(result, count):
        for i in range(1, count//2+1):
            if str(result)[count-i:] == str(result)[count-2*i:count-i]:
                return
        if count == n:
            print(result)
            exit(0)
        for i in range(1, 4):
            temp = result * 10 + i
            choose_num(temp, count+1)


    n = int(sys.stdin.readline())
    choose_num(0, 0)

if __name__ == "__main__":
    solution()
