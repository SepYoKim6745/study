n = int(input())

if n == 0 :
    print('0')
    exit()

ret = ''

while n :
    if n%(-2) :
        ret = '1' + ret
        n=(n//-2)+1
    else :
        ret = '0' + ret
        n=n//-2

print(ret)