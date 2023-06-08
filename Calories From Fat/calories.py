def parseLine(istr: str):
    calories = [9, 4, 4, 4, 7]
    parts = istr.split(" ")
    percentage = 100
    total_cal = 0
    to_revisit = []
    for idx, part in enumerate(parts):
        if part[-1] == "%":
            percentage -= int(part[:-1])
            to_revisit.append(idx)
        elif part[-1] == "C":
            cals = int(part[:-1])
            total_cal += cals
            parts[idx] = cals
        else:
            cals = calories[idx] * int(part[:-1])
            total_cal += cals
            parts[idx] = cals
    for idx in to_revisit:
        parts[idx] = (total_cal / percentage) * int(parts[idx][:-1])
    return sum(parts), parts[0]


def main():
    total = 0
    fat = 0
    while True:
        line = input()
        if line == "-":
            if total > 0:
                print(str(round((fat / total)*100)) + "%")
                total = 0
                fat = 0
            else:
                break
        else:
            ntotal, nfat = parseLine(line)
            total += ntotal
            fat += nfat


if __name__ == "__main__":
    main()

