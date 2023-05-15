import sys


def print_final(res: str, h: int):
    print(res)
    print(h)


n, s, m = [int(x) for x in input().split(" ")]
s -= 1
nums = [int(x) for x in input().split(" ")]
visited = set()
h = 0

while True:
    if s < 0:
        print_final("left", h)
        break
    if s >= n:
        print_final("right", h)
        break
    if nums[s] == m:
        print_final("magic", h)
        break
    if s in visited:
        print_final("cycle", h)
        break
    visited.add(s)
    s += nums[s]
    h += 1

