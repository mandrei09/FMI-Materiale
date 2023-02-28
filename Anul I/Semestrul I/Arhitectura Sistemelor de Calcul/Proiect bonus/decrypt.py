# python decrypt output parolamea2021 input_recuperat.txt
import sys

cheie=sys.argv[1]
fisier_input=sys.argv[2]
f=open(fisier_input)
linie_criptata=f.read()
f.close()

lungime=len(linie_criptata)
lungime_cheie=len(cheie)
decriptat=[]

for i in range (lungime):
    
    bin_lista=ord(linie_criptata[i])
    bin_cheie=ord(cheie[i%lungime_cheie])
    decriptat.append(chr(bin_lista^bin_cheie))

linie_decriptata=""
linie_decriptata=linie_decriptata.join(decriptat)

fisier_output=sys.argv[3]
f=open(fisier_output,"w")
f.write(linie_decriptata)
f.close()
