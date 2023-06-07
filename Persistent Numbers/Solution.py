def try_factor(n):
    for i in range(9, 1, -1):
        if n % i == 0:
            return True, i
    return False, 0


def do_factor(n):
    res = []
    while n >= 10:
        factored, factor = try_factor(n)
        if not factored:
            return False, res
        res.append(factor)
        n //= factor
    res.append(n)
    return True, res


def main():
    n = int(input())
    output = ""
    while n >= 0:
        factored, factors = do_factor(n)
        if factored:
            if len(factors) == 1:
                output += str(1)
            factors.sort()
            for factor in factors:
                output += str(factor)
            output += "\n"
        else:
            output += "There is no such number.\n"
        n = int(input())
    print(output)


if __name__ == "__main__":
    main()
