d=int(raw_input())#taking dimension
A=[[0.0 for i in range(0,d+1)] for j in range(0,d+1)]
I=[[0.0 for i in range(0,d+1)] for j in range(0,d+1)]
tempA=[[0.0 for i in range(0,d+1)] for j in range(0,d+1)]
tempI=[[0.0 for i in range(0,d+1)] for j in range(0,d+1)]
for i in range(0,d):#taking elements
    for j in range(0,d):
        A[i][j]=float(raw_input())
print "Given matrix: "#printing matrix
print A
for k in range(0,d-1):#converting to upper triangular
    for t in range(k+1,d):#pivioting
        if A[t][k]>A[k][k]
           for n in range(0,d):
               tempA[k][n]=A[t][n]
               tempI[k][n]=I[k][n]
               A[t][n]=A[k][n]
               I[t][n]=I[k][n]
               A[k][n]=tempA[k][n]
               I[k][n]=tempI[k][n]
    for i in range(k+1,d):
        temp=A[i][k]/A[k][k]
        for j in range(0,d):
            A[i][j]=A[i][j]-A[k][j]*temp
            I[i][j]=I[i][j]-I[k][j]*temp
for k in range(0,d):#converting to identity matrix
    temp=A[k][k]
    for j in range(0,d):
        A[k][j]=A[k][j]/temp
        I[k][j]=I[k][j]/temp
for k in range(0,d-1):
    for t in range(1,d):
        i=d-1-t
        temp=A[i][i+k]
        for j in range(0,d):
            A[i][j]=A[i][j]-A[i+k][j]*temp
            I[i][j]=I[i][j]-I[i+k][j]*temp
print I
