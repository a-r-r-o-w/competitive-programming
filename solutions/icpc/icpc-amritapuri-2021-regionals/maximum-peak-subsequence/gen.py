import random

t = 1000
n = 10

print(t)
for _ in range(t):
    k = random.randint(3, n)
    print(n, k)
    perm = list(range(1, n + 1))
    random.shuffle(perm)
    for i in perm:
        print(i, end = ' ')
    print()
