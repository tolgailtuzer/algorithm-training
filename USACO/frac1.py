"""
ID: bilinme1
LANG: PYTHON3
TASK: frac1
"""
f = open("frac1.in","r")
n = int(f.read())
f.close()
liste = {}
KeyListe = []
liste[0]="0/1"
for i in range(n-1,1,-1):
    for j in range(n,i,-1):
        if(j%i!=0):
            liste[i/j]=str(i)+"/"+str(j)
for i in range(1,n+1):
    liste[1/i]="1/"+str(i)
KeyListe = list(liste.keys())
KeyListe.sort()
f=open("frac1.out","w")
for key in KeyListe:
    f.write(liste[key]+"\n")