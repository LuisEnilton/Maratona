d,m,y,n = [int(x) for x in input().split()]
d2,m2,y2 = [int(x) for x in input().split()]
total = d+30*m+360*y
total2 = d2+30*m2+360*y2
if(total2-total % 7  == 0):
    print((total2-total + n)%7 + 7)
else:    
    print((total2-total + n)%7 )