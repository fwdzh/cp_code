import sys

for _ in range(int(input())):
    cnt = [0] * 64

    for i in range(1, 64):
        print("?", pow(2,i))
        sys.stdout.flush()
        cnt[i] = int(input())

    mx = 0
    mn = 64

    for i in range(1, 64):
        mx = max(mx, cnt[i])
        mn = min(mn, cnt[i])

    ans = 0

    if(mx == mn):
        if mx == 1:
            ans = 0
        elif mx == 2:
            ans = 1
        else:
            ans = pow(2, 64) - 1
    
    else:
        tnc = 0
        for i in range(1, 64):
            if cnt[i] == mn:
                tnc += 1
                ans += pow(2, i)
        
        if tnc != mn + 1:
            ans += 1
    
    print("!", ans)
    sys.stdout.flush()