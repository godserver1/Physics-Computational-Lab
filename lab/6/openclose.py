f=open("open.txt","r") #opens file with name of "test.txt"
A=[]
A=f.read()
f.close()
f=open("close.txt","w") #opens file with name of "test.txt"
f.write(A)
f.close()
