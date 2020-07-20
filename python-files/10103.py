score1 = 100
score2 = 100
round_num = int(input())

for i in range(round_num):
    a, b = input().split()
    a = int(a)
    b = int(b)
    if a < b:
        score1 = score1 - b
    elif b < a:
        score2 = score2 - a
    else:
        continue

print(score1)
print(score2)
