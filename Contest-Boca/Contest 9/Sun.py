ds, ys = [int(n) for n in input().split()]
dm, ym = [int(n) for n in input().split()]
if (ys>ym):
    tempo = ys-ds
    while True:
        if ((tempo+ds)%ys) == 0 and ((tempo+dm)%ym) == 0:
            break
        tempo += ys
else:
    tempo = ym-dm
    while True:
        if ((tempo+ds)%ys) == 0 and ((tempo+dm)%ym) == 0:
            break
        tempo += ym
print(tempo)