n=int(raw_input())
x=[[0.0 for i in range(0,n)] for j in range(0,5)]
y=[[0.0 for i in range(0,n)] for j in range(0,2)]
for i in range(0,n):
    a,b=raw_input().split()
    a=float(a)
    b=float(b)
    x[0][i]=a
    y[0][i]=b
sumx=[0.0 for i in range(0,5)]
sumx[0]=n
sumy=[0.0 for i in range(0,3)]
for i in range(0,n):
    x[1][i]=x[0][i]*x[0][i]   #x^2
    x[2][i]=x[1][i]*x[0][i]   #x^3
    x[3][i]=x[2][i]*x[0][i]   #x^4
    sumx[1]=sumx[1]+x[0][i]   #sumx
    sumx[2]=sumx[2]+x[1][i]   #sumx^2
    sumx[3]=sumx[3]+x[2][i]   #sumx^3
    sumx[4]=sumx[4]+x[3][i]   #sumx^4
    sumy[1]=sumy[1]+x[0][i]*y[0][i]   #sumx*y
    sumy[2]=sumy[2]+x[1][i]*y[0][i]   #sumx^2*y
    sumy[0]=sumy[0]+y[0][i]   #sumy
xbar=sumx[0]/n
ybar=sumy[0]/n
A=[[0.0 for i in range(0,3)] for j in range(0,3)]
for i in range(0,3):
    for j in range(0,3):
        t=j+i
        A[i][j]=sumx[t]
coeff=[0.0 for i in range(0,3)]
for k in range(0,2):
    for i in range(k+1,3):
        temp=A[i][k]/A[k][k]
        for j in range(k+1,3):
            A[i][j]=A[i][j]-temp*A[k][j]
        sumy[i]=sumy[i]-temp*sumy[k]
coeff[2]=sumy[2]/A[2][2]
for k in range(1,3):
    i=2-k
    temp=sumy[i]
    for j in range(i+1,3):
        temp=temp-A[i][j]*coeff[j]
    coeff[i]=temp/A[i][i]
for i in range(0,3):
    for j in range(0,3):
        t=j+i
        A[i][j]=sumx[t]
for i in range(0,n):
    y[1][i]=coeff[0]+coeff[1]*x[0][i]+coeff[2]*x[1][i]
for i in range(0,n):
    print "%.6f %20.6f %20.6f" % (x[0][i], y[0][i], y[1][i])
