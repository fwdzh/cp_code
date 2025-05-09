a = list(map(int, input().split()))
a.sort()
if a[1] > a[0] and a[2] > a[0]:
    # a[1] > a[0] , a[0] < a[2]
    print(a[1],a[0],a[2])
else:
    print(-1)