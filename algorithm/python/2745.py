import sys
input = sys.stdin.readline

n, b = input().split()
b = int(b)
ret = 0
j = 0

for i in range(len(n)-1, -1, -1) :
    if ord(n[j]) >= 65 :
        temp = ord(n[j])-55
    else :
        temp = ord(n[j])-48
        
    ret += temp*pow(b, i)
    j+=1

print(ret)
