while True:
    t, a, b = [int(n) for n in input().split()]
    if t==0 and a == 0 and b == 0:
        break
    fator = t // (a * b)
    print(fator)
    for i in range(fator, t//2,fator):
        print(i, end=' ')
        if t % i == 0 and (fator) % i != 0:
            print(i, end=' ')
            continue
    print(t)
    
    #i%a != 0 && i%b != 0 && i%t == 0
    