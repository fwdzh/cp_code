x = 17

while 1:
    y = int(input())
    
    cnt = 0
    
    z = x ^ y

    while z > 0:
        cnt += z & 1
        z //= 2
    
    print(cnt)