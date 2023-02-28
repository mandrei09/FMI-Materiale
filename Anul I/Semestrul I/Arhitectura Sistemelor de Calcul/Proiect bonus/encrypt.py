# python encrypt parolamea2021 input.txt output

import sys

cheie=sys.argv[1]
fisier_input=sys.argv[2]
f=open(fisier_input,encoding="UTF8")
linie=f.read()
f.close()

lungime=len(linie)
lungime_cheie=len(cheie)
criptat=[]

for i in range (lungime):
    
    bin_lista=ord(linie[i])
    bin_cheie=ord(cheie[i%lungime_cheie])
    criptat.append(chr(bin_lista^bin_cheie))

linie_criptata=""
linie_criptata=linie_criptata.join(criptat)

fisier_output=sys.argv[3]
f=open(fisier_output,"w")
f.write(linie_criptata)
f.close()
