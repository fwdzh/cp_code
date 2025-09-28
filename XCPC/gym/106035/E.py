from decimal import Decimal
from fractions import Fraction
n, x = map(int, input().split())
a = list(map(int, input().split()))
sum = Fraction(0, 1)
a.sort(reverse=True)
for i in range(n):
    # sum += Decimal(a[i]) / Decimal(i + 1)
    sum += Fraction(a[i], i + 1);
# print(sum)
if sum < x:
    print("NO")
else:
    print("YES")