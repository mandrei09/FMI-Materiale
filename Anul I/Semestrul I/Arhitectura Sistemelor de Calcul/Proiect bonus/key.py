# python key.py output_concurenta input_concurenta.txt aflare_cheie
f=open("input_concurenta.txt",encoding="UTF-8")
g=open("output_concurenta","rb")
linie_in=f.read()
linie_out=g.read()

f.close()
g.close()

lungime_in=len(linie_in)
lungime_out=len(linie_out)

cheie=[]

for i in range(lungime_in):
    
    bin_in=ord(linie_in[i])
    bin_out=linie_out[i]
    cheie.append(chr(bin_in^bin_out))

text_cheie=""
text_cheie=text_cheie.join(cheie)

text_cheie=text_cheie[:15]
print(text_cheie)


