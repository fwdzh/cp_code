n = int(input())
a = list(map(int,input().split()))
ans = 0
for i in a:
    if i!=1:
        ans+=1
print(ans)