mod = 1000000007
def solve():
    a, b, k = map(int, input().split())
    r = ((a - 1) * k + 1) % mod
    c = b * (k + 1) % mod
    print(r, c)
for _ in range(int(input())):
    solve()

'''
112121
122212
221121
'''