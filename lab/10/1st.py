import random
import math
x0=float(raw_input())
xn=float(raw_input())
h=float(raw_input())
n=int((xn-x0)/h)
x=0.0
for i in range(0,n):
    y=0.2+25*x-200*x*x+675*x*x*x-900*x*x*x*x+400*x*x*x*x*x
    #print "%.6f %20.6f" % (x,y)
    x=x+h
#Trapezoidal rule
y0=0.2+25*x0-200*x0*x0+675*x0*x0*x0-900*x0*x0*x0*x0+400*x0*x0*x0*x0*x0
yn=0.2+25*xn-200*xn*xn+675*xn*xn*xn-900*xn*xn*xn*xn+400*xn*xn*xn*xn*xn
integration1=(xn-x0)*(yn+y0)/2
#multiple Trapezoidal rule
summation1=0.0
x1=0.0
x2=0.0
for i in range(0,n):
    y1=0.2+25*x1-200*x1*x1+675*x1*x1*x1-900*x1*x1*x1*x1+400*x1*x1*x1*x1*x1
    x2=x1+h
    y2=0.2+25*x2-200*x2*x2+675*x2*x2*x2-900*x2*x2*x2*x2+400*x2*x2*x2*x2*x2
    summation1=summation1+y1+y2
    #print "%.6f %15.6f %15.6f %15.6f" % (x1,y1,x2,y2)
    x1=x1+h
integration2=(h*summation1)/2
#monte carlo
summation2=0.0
k=int(raw_input())
x=[0.0 for i in range(0,k)]
a=float(raw_input())
c=float(raw_input())
m=float(raw_input())
x[0]=float(raw_input())
for i in range(1,k):
    x[i]=(a*x[i-1]+c)%m
temp=0.0
for i in range(1,k):
    if x[i]>temp:
       temp=x[i]
temp=temp/xn
for i in range(0,k):
    x[i]=x[i]/temp
    y1=0.2+25*x[i]-200*x[i]*x[i]+675*x[i]*x[i]*x[i]-900*x[i]*x[i]*x[i]*x[i]+400*x[i]*x[i]*x[i]*x[i]*x[i]
    summation2=summation2+y1
integration3=summation2*(xn-x0)/(k)
summation3=0.0
for i in range(0,k):
    x1=random.uniform(0.0,0.8)
    y1=0.2+25*x1-200*x1*x1+675*x1*x1*x1-900*x1*x1*x1*x1+400*x1*x1*x1*x1*x1
    summation3=summation3+y1
integration4=summation3*(xn-x0)/(k)
print "%.6f %15.6f %15.6f %15.6f" % (integration1,integration2,integration3,integration4)
