total = 0
d = {"red" : 12 , "green" : 13 , "blue" : 14 }
id = 1
while True:
    colors = ["red" , "green" , "blue"  ]
    dict = {"red" : 0 , "green" : 0 , "blue" : 0 }
    s=input()
    l = s.split(":")
    s = l[1]
    sets = s.split(";")
    for set in sets:
        l = set.split(",")
        for x in l:
            a = x.split(" ")
            color = a[2]
            dict[color] = max(dict[color] , int(a[1]))    
    
    ok = True        
    for c in colors:
        if(dict[c] > d[c]):
            ok = False
    if ok :
        print(id)
        total += id
    id += 1
    print(total)