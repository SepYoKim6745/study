import sys
input = sys.stdin.readline

n, b = map(int, input().split())

ret = []

while n :
    ret.append(n%b)
    n = n//b

for i in range(len(ret)-1, -1, -1) :
    if ret[i] >= 10 :
        print(chr(ret[i]+55), end='')
    else :
        print(ret[i], end='')