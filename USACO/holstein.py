"""
ID: bilinme1
LANG: PYTHON3
TASK: holstein
"""
import itertools
def solve():
        nums=[x for x in range(feedCount)]
        for i in range(1,feedCount+1):
            for combs in itertools.combinations(nums,i):
                x=[0 for i in range(vCount)]
                counter=0
                for j in range(len(combs)):
                    for i in range(vCount):
                        x[i]+=feed[combs[j]][i]
                flag=True
                for i in range(vCount):
                    if vList[i]>x[i]:
                        flag=False
                        break
                if flag==True:
                    fpo.write(str(len(combs)))
                    for i in combs:
                        fpo.write(" "+str(i+1))
                    fpo.write("\n")
                    return

fp2=open("holstein.in","r")
fpo=open("holstein.out","w")
vCount=int(fp2.readline())
vList=[]
line=fp2.readline()
linee=line.split(" ")
for i in range(vCount):
    vList.append(int(linee[i]))
feedCount=int(fp2.readline())
feed=[]
for i in range(feedCount):
    line=fp2.readline()
    linee=line.split()
    temp=[]
    for i in range(vCount):
        temp.append(int(linee[i]))
    feed.append(temp)
solve()
fp2.close()
fpo.close()
