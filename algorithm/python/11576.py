import sys
input = sys.stdin.readline

ret = 0
ans = ''
a, b = map(int, input().split())
m = int(input())

n = list(map(int, input().split()))

for idx, val in enumerate(n[::-1]) :
    ret += val*(a**idx)

while ret :
    ans = str(ret%b) + ' ' + ans
    # ans.append(ret%b)
    ret = ret//b

print(ans)