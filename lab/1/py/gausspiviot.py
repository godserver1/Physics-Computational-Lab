#taking dimension
d=int(raw_input())
A=[[0.0 for i in range(0,d+1)] for j in range(0,d)]
X=[0.0 for i in range(0,d)]
tempA=[[0.0 for i in range(0,d+1)] for j in range(0,d)]
#taking elements
for i in range(0,d):
    for j in range(0,d+1):
        A[i][j]=float(raw_input())
#printing matrix (start)
print "Given matrix: "
print A
#converting to upper triangular
for k in range(0,d-1):
    #pivioting
    for t in range(k+1,d):
        if A[t][k]>A[k][k]:
           for n in range(0,d+1):
               tempA[k][n]=A[t][n]
               A[t][n]=A[k][n]
               A[k][n]=tempA[k][n]
    for i in range(k+1,d):
        temp=A[i][k]/A[k][k]
        for j in range(0,d+1):
            A[i][j]=A[i][j]-A[k][j]*temp
#printing upper triangular matrix
print "upper triangular matrix: "
print A
#backsubstitution
X[d-1]=A[d-1][d]/A[d-1][d-1]
for k in range(0,d):
    i=d-1-k
    temp2=0.0
    for j in range(i+1,d): 
        temp2=temp2+A[i][j]*X[j]
    X[i]=(A[i][d]-temp2)/A[i][i]
print X
