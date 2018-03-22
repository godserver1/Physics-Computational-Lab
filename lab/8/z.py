import math
import numpy as np
noofpoints=int(raw_input())
length=float(raw_input())
hdash=float(raw_input())
Ta=float(raw_input())
T0=float(raw_input())
Tend=float(raw_input())
Guess1=float(raw_input())
Guess2=float(raw_input())
difference=length/noofpoints
noofpoints=noofpoints+1
T=[[0.0 for x in range(0,noofpoints+1)]for j in range(0,5)]
#actual solution
x=0.0
y=0.0
for i in range(0,noofpoints):
    y=73.4523*math.exp(0.1*x)-53.4523*math.exp(-0.1*x)+20
    T[0][i]=y
    x=x+difference
#finite difference method
n=noofpoints-2
m=0.0
T[1][0]=T0
T[1][noofpoints-1]=Tend
d=[0.0 for x in range(0,noofpoints+1)]
u=[0.0 for x in range(0,noofpoints+1)]
l=[0.0 for x in range(0,noofpoints+1)]
c=[0.0 for x in range(0,noofpoints+1)]
for i in range(1,n+1):
    d[i]=hdash*difference*difference+2
    u[i]=-1
    l[i]=-1
    c[i]=hdash*difference*difference*Ta
c[1]=hdash*difference*difference*Ta+T[1][0]
c[n]=hdash*difference*difference*Ta+T[1][10]
for i in range(1,n+1):
    m=-l[i+1]/d[i]
    d[i+1]=d[i+1]+m*u[i]
    c[i+1]=c[i+1]+m*c[i]
    l[i+1]=0
T[1][n]=c[n]/d[n]
for k in range(1,n):
    j=n-k
    T[1][j]=(c[j]-u[j]*T[1][j+1])/d[j]
#Shooting
Z1=[0.0 for x in range(0,noofpoints+1)]
Z1[0]=Guess1
T[2][0]=T0
for i in range(0,noofpoints):
    kT1=Z1[i]    #RK4
    kZ1=hdash*(T[2][i]-Ta)
    kT2=Z1[i]+kZ1*difference/2
    kZ2=hdash*(T[2][i]+kT1*difference/2-Ta)
    kT3=Z1[i]+kZ2*difference/2
    kZ3=hdash*(T[2][i]+kT2*difference/2-Ta)
    kT4=Z1[i]+kZ2*difference
    kZ4=hdash*(T[2][i]+kT2*difference-Ta)
    kT=(kT1+2*kT2+2*kT3+kT4)/6
    kZ=(kZ1+2*kZ2+2*kZ3+kZ4)/6
    T[2][i+1]=T[2][i]+kT*difference
    Z1[i+1]=Z1[i]+kZ*difference
Z2=[0.0 for x in range(0,noofpoints+1)]
Z2[0]=Guess2
T[3][0]=T0
for i in range(0,noofpoints):
    kT1=Z2[i]    #RK4
    kZ1=hdash*(T[3][i]-Ta)
    kT2=Z2[i]+kZ1*difference/2
    kZ2=hdash*(T[3][i]+kT1*difference/2-Ta)
    kT3=Z2[i]+kZ2*difference/2
    kZ3=hdash*(T[3][i]+kT2*difference/2-Ta)
    kT4=Z2[i]+kZ2*difference
    kZ4=hdash*(T[3][i]+kT2*difference-Ta)
    kT=(kT1+2*kT2+2*kT3+kT4)/6
    kZ=(kZ1+2*kZ2+2*kZ3+kZ4)/6
    T[3][i+1]=T[3][i]+kT*difference
    Z2[i+1]=Z2[i]+kZ*difference
Guess3=Guess1+((Guess2-Guess1)/(T[3][noofpoints-1]-T[2][noofpoints-1]))*(Tend-T[2][noofpoints-1])
Z3=[0.0 for x in range(0,noofpoints+1)]
Z3[0]=Guess3
T[4][0]=T0
for i in range(0,noofpoints):
    kT1=Z3[i]    #RK4
    kZ1=hdash*(T[4][i]-Ta)
    kT2=Z3[i]+kZ1*difference/2
    kZ2=hdash*(T[4][i]+kT1*difference/2-Ta)
    kT3=Z3[i]+kZ2*difference/2
    kZ3=hdash*(T[4][i]+kT2*difference/2-Ta)
    kT4=Z3[i]+kZ2*difference
    kZ4=hdash*(T[4][i]+kT2*difference-Ta)
    kT=(kT1+2*kT2+2*kT3+kT4)/6
    kZ=(kZ1+2*kZ2+2*kZ3+kZ4)/6
    T[4][i+1]=T[4][i]+kT*difference
    Z3[i+1]=Z3[i]+kZ*difference
print "x	              Exact	         Finite Differnce       Shooting"
for i in range(0,noofpoints):
    print "%.6f %20.6f %20.6f %20.6f" % (i,T[0][i],T[1][i],T[4][i])
