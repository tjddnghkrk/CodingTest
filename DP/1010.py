def fac(a):
    if a == 0:
        return 1
    elif a == 1:
        return 1
    else:
        return a * fac(a-1)

n = int(input())

for _ in range(n) :
    N, M = map(int, input().split())
    upNum = fac(M)
    downNum = fac(N) * fac(M-N)
    print(upNum // downNum)

