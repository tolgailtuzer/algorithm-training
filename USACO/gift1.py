"""
ID: bilinme1
LANG: PYTHON3
TASK: gift1
"""
fin = open ('gift1.in', 'r')
fout = open ('gift1.out', 'w')
n=int(fin.readline())
person=[]
account=[]
search=""
temp=""
    
for i in range(0,n):
    person.append(fin.readline().rstrip('\n'))
    account.append(0)

while True:
    search=fin.readline().rstrip('\n')
    if not search:
        break
    try:
        cash,pN=map(int,fin.readline().split())
        calc = int(cash) // int(pN)
    except:
        continue

    for i in range(0,n):
        if person[i]==search:
            account[i]-=cash
            account[i]+=cash%pN
                
    for  i in range(0,pN):
        temp=fin.readline().rstrip('\n')
        for i in range(0,n):
            if person[i]==temp:
                account[i]+=calc
        
for i in range(0,n):
    fout.write (str(person[i])+" "+str(account[i])+ '\n')

fout.close()
