p=input()
ls=p.split()
#print("Lista:",ls)
l=len(ls)
ok=0
for i in range(l):
    L=len(ls[i])
    if l>2 and p.find("-")==-1:
        ok=1
    elif L<3:
        ok=1
        break
    elif ls[i].count('-')>1:
        ok=1
        break
    else:
        poz=ls[i].find('-')
        #print("Pozitia la care se afla - este",poz)
        for j in range(1,L):
            if ('a'>ls[i][j]>'z') and ls[i][j]!='-' and 'A'>ls[i][poz+1]>'Z':
                ok=1
                break
            elif not('A'<=ls[i][0]<='Z'):
                ok=1
                break
if ok==1:
    print("Nu este nume")
else:
    print("Este nume")