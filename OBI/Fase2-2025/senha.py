def main():
    n, m, k = map(int, input().split())
    s = input().strip()
    w = [input().strip() for _ in range(m)]
    p = int(input())

    w = ["".join(sorted(s)) for s in w]

    tot = 0
    aux = ""

    for i in range(m):
        for c in w[i]:
            #print(tot)
            calc = pow(k, (m - i - 1))
            if tot + calc >= p:
                #print(f"{i} : {c}")
                aux += c
                break
            tot += calc

    j = 0
    s_list = list(s)
    for idx, ch in enumerate(s_list):
        if ch == '#':
            s_list[idx] = aux[j]
            j += 1

    print("".join(s_list))


if __name__ == "__main__":
    main()