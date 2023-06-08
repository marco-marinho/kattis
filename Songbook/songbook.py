def main():
    t, n = [int(x) for x in input().split(" ")]
    t *= 60
    songs = [int(x) for x in input().split(" ")]
    songs.sort()
    res = 0
    for song in songs:
        if song <= t:
            t -= song
            res += song
        else:
            break
    print(res)


if __name__ == "__main__":
    main()

