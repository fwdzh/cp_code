'''
最小的一定删不掉 最大的一定删不掉


'''
n = int(input())
a = list(map(int, input().split()))
a.sort()
print((a[0] + a[n - 1]) // 2)