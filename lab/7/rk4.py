print "   x          yeu        yhe       yr-k       zeu        zhe       zr-k       yerre-r    yerrh-r    zerre-r    zerrh-r"
import math
xi = float(raw_input())
xf = float(raw_input())
yi = float(raw_input())
zi = float(raw_input())
steps = int(raw_input())
h = ((xf) - (xi))/(steps)
y = [[0.0 for i in range(steps+2)] for j in range(6)]
y[0][0] = yi
y[1][0] = zi
y[2][0] = yi
y[3][0] = zi
y[4][0] = yi
y[5][0] = zi
errory = [[0.0 for i in range(steps+1)] for j in range(3)]
errorz = [[0.0 for i in range(steps+1)] for j in range(3)]
x = xi
#eulers
for i in range(0,steps+1):
    dy = y[0][i]*y[1][i] + math.cos(x) - 0.5*math.sin(2*x) #eulers
    dz = y[0][i]*y[0][i] + y[1][i]*y[1][i] - (1+math.sin(x))
    y[0][i+1] = y[0][i] + dy*h
    y[1][i+1] = y[1][i] + dz*h
    dy1 = y[2][i]*y[3][i] + math.cos(x) - 0.5*math.sin(2*x)  #heuns
    yh1 = y[2][i] + dy1*h
    dz1 = y[2][i]*y[2][i] + y[3][i]*y[3][i] - (1+math.sin(x))
    zh1 = y[3][i] + dz1*h
    dy2 = yh1*zh1 + math.cos(x+h) - 0.5*math.sin(2*(x+h))
    dz2 = yh1*yh1 + zh1*zh1 - (1+math.sin(x+h))
    dyh = (dy1 + dy2)/2
    dzh = (dz1 + dz2)/2
    y[2][i+1] = y[2][i] + dyh*h
    y[3][i+1] = y[3][i] + dzh*h
    ky1 = y[4][i]*y[5][i] + math.cos(x) - 0.5*math.sin(2*x)    #RK4
    kz1 = y[4][i]*y[4][i] + y[5][i]*y[5][i] - (1+math.sin(x))
    ky2 = (y[4][i]+ky1*h/2)*(y[5][i]+kz1*h/2) + math.cos(x+h/2) - 0.5*math.sin(2*(x+h/2))
    kz2 = (y[4][i]+ky1*h/2)*(y[4][i]+ky1*h/2) + (y[5][i]+kz1*h/2)*(y[5][i]+kz1*h/2) - (1+math.sin(x+h/2))
    ky3 = (y[4][i]+ky2*h/2)*(y[5][i]+kz2*h/2) + math.cos(x+h/2) - 0.5*math.sin(2*(x+h/2))
    kz3 = (y[4][i]+ky2*h/2)*(y[4][i]+ky2*h/2) + (y[5][i]+kz2*h/2)*(y[5][i]+kz2*h/2) - (1+math.sin(x+h/2))
    ky4 = (y[4][i]+ky3*h)*(y[5][i]+kz3*h) + math.cos(x+h) - 0.5*math.sin(2*(x+h))
    kz4 = (y[4][i]+ky3*h)*(y[4][i]+ky3*h) + (y[5][i]+kz3*h)*(y[5][i]+kz3*h) - (1+math.sin(x+h))
    ky = (ky1 + 2*ky2 + 2*ky3 + ky4)/6
    kz = (kz1 + 2*kz2 + 2*kz3 + kz4)/6
    y[4][i+1] = y[4][i] + ky*h
    y[5][i+1] = y[5][i] + kz*h
    if (i>0):
       errory[0][i] = abs((y[0][i]-y[2][i])*100/y[2][i])
       errory[1][i] = abs((y[0][i]-y[4][i])*100/y[4][i])
       errory[2][i] = abs((y[2][i]-y[4][i])*100/y[4][i])
       errorz[0][i] = abs((y[1][i]-y[3][i])*100/y[3][i])
       errorz[1][i] = abs((y[1][i]-y[5][i])*100/y[5][i])
       errorz[2][i] = abs((y[3][i]-y[5][i])*100/y[5][i])
    print "%f %10.6f %10.6f %10.6f %10.6f %10.6f %10.6f %10.6f %10.6f %10.6f %10.6f" % (x,y[0][i],y[2][i],y[4][i],y[1][i],y[3][i],y[5][i],errory[1][i],errory[2][i],errorz[1][i],errorz[2][i])
    x = x + h
