n, k = map(int, input().split())
ans = 0
while n > 0:
    if n % k:
        break
    ans += 1
    n //= k
print(ans)