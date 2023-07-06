while True:
    hora = 1
    possivel = True
    mots, maxs = [int(n for n in input().split())]
    if mots == 0 and maxs == 0:
        break
    estacionados = []
    ent, saind = [int(n) for n in input().split()]
    
    if len(estacionados) == 0:
        estacionados.append([ent, saind])
        conjuto = {x for x in range(ent, saind)}
    else:
        if saind not in conjuto:
            possivel = False
        else:
            estacionados.append([ent, saind])
            conjuto = {x for x in range(ent, saind)}
    if possivel:
        print('Sim')
    if not possivel:
        print('Nao')
