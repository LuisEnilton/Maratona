lista = ["one" , "two" , "three" , "four" , "five" , "six" , "seven" , "eight" , "nine" ]
total = 0
while True:
    s = input()
    l = [s.find(x) for x in lista]
    r = [s.rfind(x) for x in lista]
    menor = (0, len(s))
    maior = (0, -1)
    ans = 0
    digit1 = 0
    digit2 = 0
    for i,x in enumerate(l) :
        if  x < menor[1] and x != -1 :
            menor = (i  , x)
            digit1 = i + 1 
        
    for i,x in enumerate(r) :
        if x > maior[1] :
            maior = (i , x)
            digit2 = i + 1
        
    for i,c in enumerate(s):
        if(i >= menor[1] ) :
            break
        if c.isdigit():
            num = int(c)
            digit1 = num
            break
            
    for i in range(len(s) - 1, -1 , -1) :
        if( i <= maior[1] ) :
            break
        if(s[i].isdigit()) :
            num = int(s[i])
            digit2 = num
            break
    ans = digit1 * 10 +  digit2
    print(ans)
    total += ans
    print(total)
    