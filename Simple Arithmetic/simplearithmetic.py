from decimal import Decimal

if __name__ == "__main__":
    a, b, c = [Decimal(x) for x in input().split()]
    print(a * b / c)

