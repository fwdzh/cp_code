r = [0] * 100001
c = [0] * 100001
for _ in range(int(input())):
    n = int(input())
    x = list(map(int,input().split()))
    y = list(map(int,input().split()))
    # print(x)
    # print(y)

    ans = 0
    for i in range(n):
        ans += r[x[i]] + c[y[i]]
        r[x[i]] += 1
        c[y[i]] += 1
    print(ans)
    for i in range(n):
        r[x[i]] -= 1
        c[y[i]] -= 1