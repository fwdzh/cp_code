for _ in range(int(input())):
    n = int(input())
    print("YES")
    if n & 1:
        for i in range(2 * n):
            print(-1, end = " ")
        print(2)
    else:
        for i in range(2 * n + 1):
            print(-1, end = " ")
        print()