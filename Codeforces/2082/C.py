mod = 1000000007
for _ in range(int(input())):
    n = int(input())
    s = input()
    x = s.count('1')
    print((n-1+(x-1)*pow(2,mod-2,mod)%mod)%mod)