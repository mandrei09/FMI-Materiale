#Mihai Andrei-Alexandru
#grupa 141
#[4 p.] Fișierul text text.in conține, pe mai multe linii, un text în care cuvintele sunt despărțite
#prin spații și semnele de punctuație uzuale. Să se scrie în fișierul text text.out literele din textul
#dat care au frecvențele relative nenule, precum și frecvențele lor relative, conform modelului
#din exemplul de mai jos.

#def cheie(lista):
    #return 

frecventa_caracter=[0 for i in range(0,26)]
nr=0

f=open("text.in")
text=f.read()
for caracter in text:
    if 'a'<=caracter<='z' or "A"<=caracter<="Z":
        caracter=caracter.lower()
        nr+=1
        frecventa_caracter[ord(caracter)-97]+=1
f.close()

frecventa_total=[0 for i in range(0,26)]

for i in range(0,26):
    frecventa_total[i]=frecventa_caracter[i]/nr

frecventa_sort=sorted(frecventa_total)

f=open("text.out","w")
for i in range (len(frecventa_total)):
    f.write(chr(i+97))
    f.write(":")
    f.write(' ')
    format_float = "{:.3f}".format(frecventa_total[i])
    f.write(str(format_float))
    f.write('\n')
f.close()