fi=open("input.txt","r")
sum=0
for i in range(100):
    line=fi.readline()
    sum+=int(line)
print(sum)
