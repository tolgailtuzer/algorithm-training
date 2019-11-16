"""
ID: bilinme1
LANG: PYTHON3
TASK: ariprog
"""
fp1=open("ariprog.in","r")
fp2=open("ariprog.out","w")
N=int(fp1.readline())
M=int(fp1.readline())
numbers=[]
isK=False
for i in range(0,M+1):
    for j in range(0,M+1):
        if i*i+j*j not in numbers:
            numbers.append(i*i+j*j)

numbers.sort()
limit=(2*pow(M,2))//(N-1);
count=0
for i in range(1,limit+1):
    for j in range(0,len(numbers)):
        check=numbers[j]
        for k in range(1,N):
            if check>2*pow(M,2):
                break
            check+=i
            if check in numbers:
                count+=1
            else:
                break
        if count>=N-1:
            fp2.write(str(numbers[j])+" "+str(i)+"\n")
            isK=True
        count=0
if isK==False:
    fp2.write("NONE\n")
fp1.close()
fp2.close()
