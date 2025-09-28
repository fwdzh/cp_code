n = int(input())
m = n
n = 1

for i in range(20):
    n *= m
    x = n
    cnt = 0
    while x > 0:
        if x % 2 == 1:
            cnt += 1
        x //= 2
    print(cnt)