from math import gcd
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    g = 0
    for i in a:
        g = gcd(g, abs(i - a[0]))
    sum = 0
    for i in range(1, n):
        sum += a[i - 1]
        print(gcd(g, sum), end = " ")
    sum += a[n - 1]
    print(sum)