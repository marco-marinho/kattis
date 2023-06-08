from typing import List


def convolve(l1: List, l2: List):
    n = len(l1)
    m = len(l2)
    output = (n + m - 1) * [0]

    for i in range(n):
        for j in range(m):
            output[i + j] += l1[i] * l2[j]

    return output


def main():
    T = int(input())
    output = ""
    for _ in range(T):
        d1 = int(input())
        p1 = [int(x) for x in input().split(" ")]
        d2 = int(input())
        p2 = [int(x) for x in input().split(" ")]
        output += str(d1 + d2) + "\n"
        output += " ".join(map(str, convolve(p1, p2))) + "\n"
    print(output)


if __name__ == "__main__":
    main()

