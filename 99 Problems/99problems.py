n = int(input())

if 100 >= n:
    print(99)
else:
    base = n - (n % 100)
    first = base + 99
    second = base - 1
    if first - n <= n - second:
        print(first)
    else:
        print(second)