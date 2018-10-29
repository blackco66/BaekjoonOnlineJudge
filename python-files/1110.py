count = 0
a = int(input())
num = a
while True:
    b = a % 10
    c = int(a / 10)
    d = b + c
    d %= 10
    a = b * 10 + d
    count += 1
    if num == a:
        break
print(count)
