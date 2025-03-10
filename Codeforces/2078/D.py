for _ in range(int(input())):
    n = int(input())
    a = [[]]
    for i in range(n):
        s=list(input().split())
        a.append(s)
    # for i in range(n+1):
    #     print(a[i])
    p1=[0]*(n+2)
    p2=[0]*(n+2)
    p1[n+1]=1
    p2[n+1]=1
    
    for i in range(n,0,-1):
        # print(i)
        p1[i]=p1[i+1]
        p2[i]=p2[i+1]
        if a[i][0]=='x':
            p1[i]*=int(a[i][1])
            # print(a[i][0])
        if a[i][2]=='x':
            p2[i]*=int(a[i][3])
    # p1=
    # print(p1,p2)
    L=1
    R=1
    for i in range(1,n+1):
        x=0
        # print(int(a[i][1]),int(a[i][3]))
        if a[i][0]=='x':
            x+=(int(a[i][1])-1)*L
        else:
            x+=int(a[i][1])
        if a[i][2]=='x':
            x+=(int(a[i][3])-1)*R
        else:
            x+=int(a[i][3])
        if p1[i+1]>p2[i+1]:
            L+=x
        else:
            R+=x
    print(L+R)
# 4
# + 9 x 2  , 1 11
# x 2 x 3  , 1
# + 9 + 10 , 
# x 2 + 1  , 