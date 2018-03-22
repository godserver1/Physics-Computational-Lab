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
T[1][0]=T0
T[1][noofpoints-1]=Tend
coeff=[[0.0 for x in range(0,noofpoints+1)] for y in range(0,4)]
u=[0.0 for x in range(0,noofpoints+1)]
l=[0.0 for x in range(0,noofpoints+1)]
c=[0.0 for x in range(0,noofpoints+1)]
for i in range(1,noofpoints-1):
    coeff[0][i]=hdash*difference*difference+2
    coeff[1][i]=-1
    coeff[2][i]=-1
    coeff[3][i]=hdash*difference*difference*Ta
coeff[3][1]=hdash*difference*difference*Ta+T[1][0]
coeff[3][noofpoints-2]=hdash*difference*difference*Ta+T[1][noofpoints-1]
temp=0.0
for i in range(1,noofpoints-1):
    temp=-coeff[2][i+1]/coeff[0][i]
    coeff[0][i+1]=coeff[0][i+1]+temp*coeff[1][i]
    coeff[3][i+1]=coeff[3][i+1]+temp*coeff[3][i]
    coeff[2][i+1]=0
T[1][noofpoints-2]=coeff[3][noofpoints-2]/coeff[0][noofpoints-2]
for k in range(3,noofpoints):
    j=noofpoints-k
    T[1][j]=(coeff[3][j]-coeff[1][j]*T[1][j+1])/coeff[0][j]
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
