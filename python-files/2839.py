a = int(input())
b = int(a / 5)
c = a % 5
if c == 0:
    print(b)
elif c == 1:
    if b > 0:
        print(b-1+2)
    else:
        print(-1)
elif c == 2:
    if b > 1:
        print(b-2+4)
    else:
        print(-1)
elif c == 3:
    print(b+1)
elif c == 4:
    if b > 0:
        print(b-1+3)
    else:
        print(-1)
else:
    pass 