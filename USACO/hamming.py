"""
ID: bilinme1
LANG: PYTHON3
TASK: hamming
"""
import itertools
def btoD(list):
    digit=len(list)-1
    res=0
    for i in list:
        res+=pow(2,digit)*i
        digit-=1
    return res
fp1=open("hamming.in","r")
fp2=open("hamming.out","w")
line=fp1.readline().split()
N=int(line[0])
B=int(line[1])
D=int(line[2])
res=[]
resC=0
temp=[0 for x in range(B)]
res.append(temp)
for i in itertools.product([0,1],repeat=B):
    flag=True
    for k in res:
        dist=0
        for j in range(B):
            if i[j]!=k[j]:
                dist+=1
        if dist<D:
            flag=False
            break
    if flag==True:
        #print(i,dist)
        res.append(i)
    if(len(res)==N):
        break
blank=""
count=0
for i in range(len(res)):
    fp2.write(blank+str(btoD(res[i])))
    blank=" "
    count+=1
    if count==10:
        fp2.write("\n")
        blank=""
        count=0
if count!=0:
    fp2.write("\n")
fp1.close()
fp2.close()
