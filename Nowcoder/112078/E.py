def solve():
    n = int(input())
    if n == 3:
        print("1 2 3")
    elif n & 1 or n == 2:
        print("-1")
    else:
        for i in range(1, n // 2 + 1):
            print(i, n - i + 1, end=" ")
        print()

for i in range(int(input())):
    solve()