from math import gcd

N, S = map(int, input().split())


a = list(map(int, input().split()))
ret = []

for i in a :
    ret.append(abs(i-S))

g = ret[0]

for i in ret[1:] :
    g = gcd(i, g)

print(g)