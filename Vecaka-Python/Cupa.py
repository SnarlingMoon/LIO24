N, M = map(int, input().split())
rmdr = {}
answ=0

for i in range(N):
    num, dz = map(int, input().split()) 
    num %= M
    if num in rmdr:
        if rmdr.get(num)<0:
            answ += min(abs(rmdr.get(num)),dz)
        rmdr[num] += dz
    elif (M-num) in rmdr:
        if rmdr.get(M-num)>0:
            answ += min((rmdr.get(M-num)),dz)
        rmdr[M-num] -= dz
    elif num<=M/2:
        rmdr[num] = dz
    else:
        rmdr[M-num] = (-1)*dz
if 0 in rmdr:
    answ += int(rmdr.get(0)/2)
if (M/2) in rmdr:
    answ += int(rmdr.get(M/2)/2)
print(answ)
