for _ in range(int(input())):
    n, m, k = map(int, input().split())
    b = list(map(int, input().split()))
    r = list(map(int, input().split()))
    score = [0] * n
    # p = [[]] * m
    p = [[] for i in range(m)]
    for i in range(m):
        p[i] = list(map(int, input().split()))
    x = list(map(int, input().split()))
    y = list(map(int, input().split()))
    # print(x,y);
    # print(p)
    pmax = [0] * m # 每场比赛的最高分
    # get = [[]] * n
    get = [[] for i in range(n)]
    for i in range(m):
        for j in range(n):
            pmax[i] = max(pmax[i], p[i][j])
    
    for i in range(n):
        
        for j in range(m):
            if p[j][i] == -1:
                get[i].append(0)
            elif p[j][i] == 0:
                get[i].append(b[j])
            else:
                # print(type(pmax[j]))
                # num = r * (int)(p[j][i]) + pmax[j] - 1
                # print(num)
                # print((b[j] + (r[j] * p[j][i]) // pmax[j]))
                get[i].append(b[j] + (r[j] * p[j][i]) // pmax[j])
        # print(i,get[i])
    # print(get)
    ans = 0
    for i in range(n):
        # print(get[i])
        get[i].sort(reverse = True)
        # print(x[i], y[i], "xy")
        A = x[i] // 60 + y[i]
        B = 0
        for j in range(k):
            B += get[i][j]
        # print(A, B, "AB")
        if A >= 50 and B >= 50 * k and (A >= 60 or B >= 60 * k):
            ans += 1
    print(ans)


