import random

y = []
while len(y) != 500:
    x = random.randint(-1000000, 1000000)
    if x not in y:
        print(x, end=" ")
        y = y + [x]
