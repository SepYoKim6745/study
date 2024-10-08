import sys
input = sys.stdin.readline
t = int(input())

prime = [True]*1000001

for i in range(2, int(1000001**0.5+1)) :
    if prime[i] == True :
        for j in range(i+i, 1000001, i) :
            prime[j] = False

while t :

    n = int(input())
    cnt = 0

    for i in range(2, n//2+1) :
        if prime[i] and prime[n-i] :
            cnt +=1

    print(cnt)
    t-=1